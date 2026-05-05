#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int n;
    cin >> n;

    map<int, int> master_freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        master_freq[x]++;
    }
    
    auto check = [&](int M) {
        map<int, int> freq = master_freq;
        vector<bool> is_missing(M, false);
        
        for (int i = 0; i < M; i++) {
            if (freq.count(i)) {
                freq[i]--;
                if (freq[i] == 0) freq.erase(i);
            } else {
                is_missing[i] = true;
            }
        }
        
        for (int i = 0; i < M; i++) {
            if (is_missing[i]) {
                auto it = freq.lower_bound(2 * i + 1);
                
                if (it != freq.end()) {
                    it->second--;
                    if (it->second == 0) freq.erase(it);
                } else {
                    return false; 
                }
            }
        }
        return true;
    };
    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;       
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // setIO("check");
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}