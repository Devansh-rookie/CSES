#include<bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define MODN 1000003
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vi fact_dp(MODN + 1, 1);
vi factinv_dp(MODN + 1, 1);

int modexp(int x, int y){
    if(y == 0) return 1;
    if(y == 1) return x;
    if(y % 2 == 0) return modexp((1LL*x*x)%MODN, y/2)%MODN;
    return (x*modexp((1LL*x*x)%MODN, y/2))%MODN;
}

int modinv(int n){
    return modexp(n, MODN - 2);
}
void precompute_fact(){
    for(int i = 1; i < MODN; i++){
        fact_dp[i] = (1LL * fact_dp[i-1] * i) % MODN;
    }
}

void precompute_inv_fact(){
    factinv_dp[MODN - 1] = modinv(fact_dp[MODN - 1]);

    for(int i = MODN - 1; i >= 1; i--){
        factinv_dp[i - 1] =
            (1LL * factinv_dp[i] * i) % MODN;
    }
}


int fact(int n){
    if(n >= MODN) return 0;
    return fact_dp[n];
}

int inv_fact(int n){
    return factinv_dp[n];
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    int value = INT_MAX;
    for(int i = 0;i < n;i++){
        value = min(value, b[i]/a[i]);
    }
    int log_val = 0;
    while(pow(2, log_val) <= value){
        log_val++;
    }
    log_val--;
    vi k(n, 0);
    vvi comp(log_val + 1, vi(n, 0));
    for(int i = 0;i < n;i++){
        int cur = a[i];
        int temp_k = max(0, b[i] / (1 << log_val) - cur);
        cur += temp_k;
        k[i] += temp_k;
        b[i] -= cur * (1 << log_val);
        comp[log_val][i] = temp_k;
        for(int j = log_val - 1;j >= 0;j--){
            temp_k = b[i] / (1 << j);
            k[i] += temp_k;
            b[i] -= temp_k * (1 << j);
            comp[j][i] = temp_k;
        }
    }
    ll suma = 0;
    for(int i = 0 ;i < n;i++){
        suma += k[i];
    }
    cout << suma + log_val << ' ';

    ll ans = 1;

    for(int j = 0;j <= log_val;j++){
        ll sumation = 0;
        for(int i = 0;i < n;i++){
            sumation += comp[j][i];
            if(sumation >= MODN){
                cout << 0 << '\n';
                return;
            }
        }
        ll inv = 1;
        for(int i = 0;i < n;i++){
            inv = (inv * inv_fact(comp[j][i]))%MODN;
        }
        ans = (ans *(fact(sumation) * inv)%MODN)%MODN;
    }

    cout << ans << '\n';
}

signed main() {
    precompute_fact();
    precompute_inv_fact();
    // setIO("check");
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
