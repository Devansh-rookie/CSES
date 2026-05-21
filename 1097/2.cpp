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

int main(){
    // setIO("check");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> m;
        for(int i = 0;i < n;i++){
            cin >> a[i];
            m[a[i]]++;
        }
        long long ans = 0;
        auto it = m.rbegin(); 
        int max_val = it->first;
        vector<int> b;
        b.push_back(max_val);
        m[max_val]--;
        for(auto [val, freq] : m){
            if(freq>0){
                b.push_back(val);
                m[val]--;
            }
        }
        for(auto [val, freq] : m){
            while(m[val]>0){
                b.push_back(val);
                m[val]--;
            }
        }

        int maxx = 0;
        int mexx = 0;
        vector<bool> present(n+2);
        for(int i = 0;i < n;i++){
            maxx = max(maxx, b[i]);
            if(b[i] <=n){
                present[b[i]] = true;
            }
            while(present[mexx]){
                mexx++;
            }
            ans += (long long) maxx + (long long)mexx;
        }
        cout << ans << endl;
    }

    return 0;
}