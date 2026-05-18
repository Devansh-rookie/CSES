#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r",   stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}


// Helper function to check if a given target maximum time is feasible
bool isValid(long long target_time, int N, int M, int C, const vector<long long>& brew, const vector<int>& cursed) {
    int segments_needed = 1;
    long long current_segment_brew = 0;
    int current_segment_cursed = 0;

    for (int i = 0; i < N; ++i) {
        long long next_brew = current_segment_brew + brew[i];
        int next_cursed = current_segment_cursed + cursed[i];

        long long effective_time = next_brew;
        if (next_cursed > C) {
            effective_time *= 2;
        }

        // If adding the current potion keeps the time within the target limit, add it
        if (effective_time <= target_time) {
            current_segment_brew = next_brew;
            current_segment_cursed = next_cursed;
        } else {
            // Otherwise, start a new segment with the current potion
            segments_needed++;
            current_segment_brew = brew[i];
            current_segment_cursed = cursed[i];
        }
    }

    // Check if we managed to do it within the allowed number of apprentices
    return segments_needed <= M;
}

// Main logic function as per the required format
long long breweryAssign(int N, int M, int C, vector<long long> brew, vector<int> cursed) {
    long long low = 0;
    long long total_brew = 0;
    int total_cursed = 0;

    // Determine the lower and upper bounds for the binary search
    for (int i = 0; i < N; ++i) {
        long long single_time = brew[i];
        if (cursed[i] > C) {
            single_time *= 2;
        }
        low = max(low, single_time);
        total_brew += brew[i];
        total_cursed += cursed[i];
    }

    long long high = total_brew;
    if (total_cursed > C) {
        high *= 2;
    }

    long long ans = high;

    // Binary search to minimize the maximum completion time
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isValid(mid, N, M, C, brew, cursed)) {
            ans = mid;       // This time limit is possible, record it
            high = mid - 1;  // Try to find an even smaller valid maximum time
        } else {
            low = mid + 1;   // Time limit is too strict, we need more time
        }
    }

    return ans;
}

// ---------------------------------------------------------
// Main function strictly to test the code locally
// ---------------------------------------------------------
int main() {
    // Fast I/O
    setIO("check");
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int N, M, C;
    // Read N, M, C
    if (cin >> N >> M >> C) {
        vector<long long> brew(N);
        for (int i = 0; i < N; ++i) {
            cin >> brew[i];
        }

        vector<int> cursed(N);
        for (int i = 0; i < N; ++i) {
            cin >> cursed[i];
        }

        // Output the result
        cout << breweryAssign(N, M, C, brew, cursed) << "\n";
    }

    return 0;
}
