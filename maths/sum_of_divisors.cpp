#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <utility>
#include <vector>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e6;

vector<bool> sv(MAXN + 1, true);
vi primes;
void sieve(){
    for(int i = 2;i <= MAXN;i++){
        if(!sv[i]) continue;
        for(ll j = 1LL*i*i;j <= MAXN; j += i){
            sv[j] = false;
        }
    }
    for(int i = 2;i <= MAXN;i++){
        if(sv[i]) primes.push_back(i);
    }
}
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

map<int, int> m;

void prime_factors(ll n){
    for(int i: primes){
        if(1LL* i * i > n) break;
        while(n%i == 0){
            m[i]++;
            n /= i;
        }
    }
    if(n > 1){
        m[n]++;
    }
}

ll powmod(ll a, ll b, int MOD){
    if(!b) return 1;
    ll half_power = powmod(a, b/2, MOD);
    if(!(b % 2)) return ((1LL * half_power * half_power)%MOD)%MOD; // or use (long long), else there would be interger overflow
    return (((1LL * half_power * half_power)%MOD)* 1LL * a)%MOD;
}

// ll sumation(int i, vpii & factors){
//     if(i == factors.size()) return 1;
//     ll ans = 0;
//     for(int power = 0;power <= factors[i].second;power++){
//         ans = (ans + (powmod(factors[i].first, power, MOD) * sumation(i + 1, factors))%MOD)%MOD;
//     }
//     return ans;
// }

ll sumation(ll n){
    n %= MOD;
    return n * ((n + 1) % MOD) % MOD * ((MOD + 1) / 2) % MOD;
}

int main() {
    setIO();
    ll n;
    cin >> n;
    // sieve();
    // prime_factors(n);
    // vpii factors;
    // for(auto const &[p, i]: m){
    //     factors.emplace_back(p, i);
    // }
    ll ans = 0;
    for(ll d = 1; d <= n;){
        ll q = n/d;
        ll end = n/q;
        ans = (ans + ((sumation(end) - sumation(d - 1) + MOD)%MOD)*(q))%MOD;
        d = end + 1;
    }
    cout << (ans%MOD) << '\n';
    return 0;
}
