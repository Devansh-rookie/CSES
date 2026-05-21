#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    long long K;
    cin >> K;

    // A mountain range requires at least 3 points to have a peak
    if (N < 3) {
        cout << 0 << "\n";
        return;
    }

    // Precalculate the optimal "minimum cost" base height for each possible peak position.
    // This removes the non-monotonic nature of the direct cost function.
    vector<long long> M(N);
    for (int i = 1; i < N - 1; ++i) {
        M[i] = max(A[i], min(A[i-1] + 1, A[i+1] + 1));
    }

    // Helper lambda to check if a peak of height H is achievable anywhere
    auto isValid = [&](long long H) {
        for (int i = 1; i < N - 1; ++i) {
            // Pick the cheapest target height that satisfies being >= H
            long long optimal_T = max(H, M[i]);

            long long cost = (optimal_T - A[i])
                           + max(0LL, A[i-1] - optimal_T + 1)
                           + max(0LL, A[i+1] - optimal_T + 1);

            if (cost <= K) return true;
        }
        return false;
    };

    // If we can't even form a peak of height 0, return 0 early
    if (!isValid(0)) {
        cout << 0 << "\n";
        return;
    }

    // Binary search bounds: maximum possible element is 10^9 + K (10^9)
    long long low = 0, high = 3000000000LL;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isValid(mid)) {
            ans = mid;       // 'mid' is achievable, record it
            low = mid + 1;   // Try to find a higher peak
        } else {
            high = mid - 1;  // 'mid' is too high, scale back
        }
    }

    cout << ans << "\n";
}
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    // Fast I/O
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    setIO("check");

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
