#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

vector<ll> calculateLuckyValue(const vector<pair<ll, ll>>& testCases) {
    vector<ll> results;

    for (const auto& [n, k] : testCases) {
        ll luckyValue = 0;
        stack<pair<ll, ll>> segments;
        segments.push({1, n}); // Start with the full range

        while (!segments.empty()) {
            auto [l, r] = segments.top();
            segments.pop();

            ll length = r - l + 1;

            if (length < k) {
                continue;
            }

            ll mid = (l + r) / 2;

            // If the length is odd, add the middle star to lucky value
            if (length % 2 == 1) {
                luckyValue += mid;
                segments.push({l, mid - 1});
                segments.push({mid + 1, r});
            } else {
                segments.push({l, mid});
                segments.push({mid + 1, r});
            }
        }

        results.push_back(luckyValue);
    }

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<pair<ll, ll>> testCases(t);

    for (int i = 0; i < t; ++i) {
        cin >> testCases[i].first >> testCases[i].second;
    }

    vector<ll> results = calculateLuckyValue(testCases);

    for (ll result : results) {
        cout << result << "\n";
    }

    return 0;
}
