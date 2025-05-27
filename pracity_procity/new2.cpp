#include<bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

using ll = long long;

int main() {
    // setIO("check");

    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        if(x == 0 && n == 1){
            cout << -1 << endl;
            continue;
        }
        ll ans = 0;
        if(x == 0 && n%2 != 0){
            ans = 3 + 2 + 1 + (n - 3);
            cout << ans << endl;
            continue;
        }
        if(x == 1 && n%2 == 0){
            ans = 3 + 2 + (n - 2);
            cout << ans << endl;
            continue;
        }
        int k = __builtin_popcountll(x);//number of set bits
        if(n - k > 0){
            int h = n - k;
            if(h%2 != 0){
                h++;
            }
            ans = h;
            ans += x;
            cout << ans << endl;
            continue;
        }
        else if(n - k == 0){
            ans = x;
            cout << ans << endl;
            continue;
        }
        else{
            for(int i = 0;i < n - 1;i++){
                if((1 << i) & x){
                    ans += 1 << i;
                    x = x ^ (1 << i);
                }
            }
            ans += x;
        }

        cout << ans << endl;
    }

    return 0;
}
