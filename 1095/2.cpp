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
        for(int i = 0;i < n - 1;i++){
            if(abs(a[i]-a[i+1]) == gcd(a[i], a[i+1])){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}