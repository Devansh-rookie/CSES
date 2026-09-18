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
const int MAXN = 2e5;

vi spf(MAXN + 1);
vpii min_val(MAXN + 1, {INT_MAX, INT_MAX});
vi freq(MAXN + 1, 0);
void sieve(){
    for(int i = 2;i <= MAXN;i++)spf[i] = i;
    for(int i = 2;i*i <= MAXN;i++){
        if(spf[i] == i){
            for(int j = i*i;j <= MAXN;j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
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

void prime_factors(int n){
    while(n > 1){
        int prime = spf[n];
        freq[prime]++;
        int power = 0;
        while(n % prime == 0){
            n/=prime;
            power++;
        }
        if(power < min_val[prime].first) {
            min_val[prime].second = min_val[prime].first;
            min_val[prime].first = power;
        }
        else if(power < min_val[prime].second) {
            min_val[prime].second = power;
        }
    }
}

ll power(ll a, int b) {
    ll res = 1;
    while(b--) res *= a;
    return res;
}

int main() {
    setIO();

    int n;
    cin >> n;
    vi a(n, 0);
    sieve();
    for(int i = 0;i < n;i++) cin >> a[i];

    // one array vpi vi one for minimum 2 and one for frequency

    for(int i = 0;i < n;i++){
        prime_factors(a[i]);
    }

    ll ans = 1;

    for(int i = 2;i <= MAXN;i++){
        if(freq[i] == n){
            ans = 1LL * ans * power(i, max(min_val[i].first, min_val[i].second));
        }
        else if(freq[i] == n - 1){
            ans = 1LL * ans * power(i, min(min_val[i].first, min_val[i].second));
        }
    }

    cout << ans << '\n';

    return 0;
}
