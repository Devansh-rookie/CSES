import requests
import time
import math
import os
import json

class CodeforcesPredictor:
    def __init__(self):
        # Setup local cache path in the present working directory (pwd)
        self.cache_dir = "cache"
        self.cache_file = os.path.join(self.cache_dir, "ratings.json")
        self.ratings_cache = {}
        
        self._load_cache()
        
    def _load_cache(self):
        """Loads ratings from the local JSON file if it exists."""
        if os.path.exists(self.cache_file):
            try:
                with open(self.cache_file, 'r') as f:
                    self.ratings_cache = json.load(f)
                print(f"Loaded {len(self.ratings_cache)} users from local cache.")
            except json.JSONDecodeError:
                print("Cache file corrupted. Starting fresh.")
        else:
            # Create the cache directory if it doesn't exist
            os.makedirs(self.cache_dir, exist_ok=True)

    def _save_cache(self):
        """Saves the current RAM cache back to the local JSON file."""
        with open(self.cache_file, 'w') as f:
            json.dump(self.ratings_cache, f)

    def get_contest_data(self, contest_id, target_handle):
        print(f"Fetching standings for contest {contest_id}...")
        
        # 1. Fetch using the heavily cached, parameter-less URL
        url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}"
        response = requests.get(url).json()
        
        if response['status'] != 'OK':
            print("Failed to fetch standings:", response.get('comment'))
            return
            
        rows = response['result']['rows']
        target_rank = None
        handles_in_contest = []
        
        # 2. Parse handles and MANUALLY filter for official contestants
        for row in rows:
            party = row['party']
            
            # Skip virtual participants, practice submissions, or out-of-competition users
            if party.get('participantType') != 'CONTESTANT':
                continue
                
            # Most parties have 1 member for standard contests
            handle = party['members'][0]['handle']
            handles_in_contest.append(handle)
            
            if handle == target_handle:
                target_rank = row['rank']
                
        if not target_rank:
            print(f"User {target_handle} not found in official standings.")
            return
            
        print(f"Found {len(handles_in_contest)} official participants. Target rank: {target_rank}")
        
        # 3. Fetch ratings for all official participants (using Cache)
        opponent_ratings = self.fetch_ratings_in_chunks(handles_in_contest)
        
        # 4. Calculate Delta
        target_rating = self.ratings_cache.get(target_handle, 1500)
        
        delta, perf = self.calculate_raw_delta(target_rating, target_rank, opponent_ratings)
        
        print("\n--- PREDICTION ---")
        print(f"Current Rating: {target_rating}")
        print(f"Contest Rank: {target_rank}")
        print(f"Performance: {perf}")
        print(f"Predicted Delta: {delta > 0 and '+' or ''}{delta}")

    def fetch_ratings_in_chunks(self, handles):
        # Filter out handles we already have in our RAM/Local cache
        missing_handles = [h for h in handles if h not in self.ratings_cache]
        
        if missing_handles:
            print(f"Fetching ratings for {len(missing_handles)} uncached users...")
            
            chunk_size = 200 
            new_users_fetched = False
            
            for i in range(0, len(missing_handles), chunk_size):
                chunk = missing_handles[i:i + chunk_size]
                handles_str = ";".join(chunk)
                
                url = f"https://codeforces.com/api/user.info?handles={handles_str}"
                response = requests.get(url)
                
                if response.status_code != 200:
                    print(f"Server error on chunk {i}: HTTP {response.status_code}")
                    continue
                
                try:
                    data = response.json()
                    if data['status'] == 'OK':
                        for user in data['result']:
                            # If a user is unrated, default to 1500
                            self.ratings_cache[user['handle']] = user.get('rating', 1500)
                        new_users_fetched = True
                except requests.exceptions.JSONDecodeError:
                    print("Failed to decode JSON. The API might be temporarily down.")
                
                # Respect the 5 requests/sec rate limit
                time.sleep(0.5) 
                
            # Save to disk only if we actually downloaded new data
            if new_users_fetched:
                self._save_cache()
                print("Cache updated and saved to local folder.")
        else:
            print("All ratings loaded directly from local cache!")

        # Return a simple list of all opponent ratings for the math formula
        return [self.ratings_cache[h] for h in handles]

    # --- Math Functions ---
    def get_probability(self, rating_a, rating_b):
        return 1.0 / (1.0 + 10.0 ** ((rating_b - rating_a) / 400.0))

    def get_seed(self, hypothetical_rating, opponent_ratings):
        seed = 1.0
        for opp_rating in opponent_ratings:
            seed += self.get_probability(opp_rating, hypothetical_rating)
        return seed

    def calculate_raw_delta(self, user_rating, actual_rank, opponent_ratings):
        initial_seed = self.get_seed(user_rating, opponent_ratings)
        m = math.sqrt(actual_rank * initial_seed)
        
        low, high = 10.0, 8000.0
        while (high - low) > 0.5:
            mid = (low + high) / 2.0
            mid_seed = self.get_seed(mid, opponent_ratings)
            
            if mid_seed < m:
                high = mid
            else:
                low = mid
                
        performance_rating = (low + high) / 2.0
        return int((performance_rating - user_rating) / 2.0), int(performance_rating)

# Run the script
if __name__ == "__main__":
    predictor = CodeforcesPredictor()
    
    # Replace with the actual contest ID and handle you want to check
    predictor.get_contest_data(contest_id=2231, target_handle="devansh151005")