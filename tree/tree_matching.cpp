#include<bits/stdc++.h>
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

vvi adj;

int main(){
    int n;
    cin >> n;
    return 0;
}
