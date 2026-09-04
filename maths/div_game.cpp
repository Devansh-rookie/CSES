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

vi get_prime_exponents(ll n){
    vi ans;
    int exp = 0;
    while(n%2 == 0){
        n/=2;
        exp++;
    }
    if(exp > 0) ans.pb(exp);

    for(ll d = 3;d*d <= n; d += 2){
        if(n%d != 0) continue;
        int val = 0;
        while(n % d == 0){
            n/=d;
            val++;
        }
        ans.pb(val);
    }

    if(n > 1) ans.pb(1);
    return ans;
}

int num_ways(int n){
    return floor((sqrt(8*n + 1) - (double)1)/(2.0) + 1e-9);
}

int main() {
    // setIO("check");

    ll n;
    cin >> n;
    ll ans = 0;
    vi exponents = get_prime_exponents(n);
    for(int e: exponents){
        ans += num_ways(e);
    }
    cout << ans << '\n';
    return 0;
}
