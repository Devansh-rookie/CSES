#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
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

    int n;
    cin >> n;
    ll prod = 1;
    vi ans;
    for(int i = 1;i < n - 1;i++){
        if(__gcd(i, n) == 1){
            prod = (prod*i)%n;
            ans.pb(i);
        }
    }
    prod = (prod*(n-1))%n;
    if(prod == 1){
        ans.pb(n-1);
    }
    cout << ans.size() << '\n';
    for(int i: ans){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
