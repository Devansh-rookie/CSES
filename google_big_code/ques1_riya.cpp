#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Function to simulate the segment formation process for a given D
bool check(long long D, const vector<long long>& A, long long K) {
    int n = A.size();
    long long count = 0;
    deque<int> dq; // Stores indices of candidate left endpoints

    for (int j = 0; j < n; ++j) {
        // Step 1: Eviction - Maintain strictly decreasing order of scores
        while (!dq.empty() && A[dq.back()] <= A[j]) {
            dq.pop_back();
        }

        // Step 2: Registration - Add the current station as a new candidate
        dq.push_back(j);

        // Step 3: Matching - Check if the leftmost valid candidate satisfies the drop threshold D
        while (!dq.empty() && A[dq.front()] - A[j] >= D) {
            count++;
            dq.pop_front(); // Left endpoint is permanently removed after being matched
        }

        // Optimization: Early exit if we already met the required K segments
        if (count >= K) {
            return true;
        }
    }

    return count >= K;
}

void solve() {
    int N;
    long long K;

    // Read N and K
    if (!(cin >> N >> K)) return;

    vector<long long> A(N);
    // Read quality scores
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Binary Search space for D [0, 10^9]
    long long low = 0, high = 1e9;
    long long ans = 0; // The answer naturally defaults to 0 if the process fails even at D = 0

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(mid, A, K)) {
            ans = mid;       // Store the maximum valid D found so far
            low = mid + 1;   // Try to find a larger minimum drop
        } else {
            high = mid - 1;  // D is too large, need to test smaller drops
        }
    }

    // Print the optimal maximum minimum quality drop D
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
