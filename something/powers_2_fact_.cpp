#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvl = vector<vll>;
#define MAXN 1e12
#define all(x) x.begin(), x.end()

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vll fact;

void precompute(){
    fact.push_back(1);
    for(int i = 0;;i++){
        if(fact[i] >= MAXN) break;
        fact.push_back(1LL*(i + 1)*fact[i]);
    }
}

ll largest_pow_2(ll n){
    ll ans = 1;
    while(ans <= n){
        ans *= 2;
    }
    return ans / 2;
}

void solve(){
    ll n;
    cin >> n;
    ll ans = INT_MAX;
    // while(n > 0){
    //     auto it = upper_bound(all(fact), n);
    //     ll some_fact = (it == fact.begin())?0:*(--it);
    //     ll some_val = max(some_fact, 1LL * largest_pow_2(n));
    //     n -= some_val;
    //     ans++;
    // }
    for(int mask = 0;mask < (1 << fact.size());mask++){
        ll sumation = 0;
        ll something_else = 0;
        for(int j = 0;j < fact.size();j++){
            if(mask & (1 << j)){sumation += fact[j];something_else++;}
        }
        ll something = n - sumation;
        if(something <= n) ans = min(ans, something_else + 1LL * __builtin_popcountll(something));
    }
    cout << ans << '\n';
}

int main() {
    setIO("");
    precompute();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
