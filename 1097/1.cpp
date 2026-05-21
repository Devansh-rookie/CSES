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
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        long long rolling_sum = max(a[n - 1], 0);
        int ans = 0;
        if(a[n-1] > 0) ans++;
        for(int i = n - 2;i >= 0;i--){
            rolling_sum = max(rolling_sum + a[i], 0ll);
            if(rolling_sum > 0 ) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}