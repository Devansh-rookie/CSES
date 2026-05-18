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
const int MOD = 676767677;
int main() {
    // setIO("check");
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(a[i]!= 1){
                ans = (ans + a[i])%MOD;
            }
        }
        if(a[n-1] == 1) ans = (ans+1)%MOD;
        cout << ans << endl;
    }
    return 0;
}