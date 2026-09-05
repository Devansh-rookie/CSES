#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e6;
vi phi(MAXN + 1, 0);
vll summ(MAXN + 1, 0);
void precompute(vi &phi) {
    for(int i = 2;i <= MAXN; i++) {
        if(phi[i] == i){
            for(int j = i;j <= MAXN;j+=i){
                phi[j] = phi[j] - phi[j]/i;// n*(1 - 1/p)
            }
        }
    }

    for(int d = 1;d <= MAXN;d++){
        for(int j = d; j <= MAXN;j+=d){
            summ[j] += 1LL * d * phi[d];
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

ll solve(int n){
    return 1LL*(n*(summ[n] + 1))/2;
}

int main() {
    setIO("check");
    iota(all(phi), 0);
    precompute(phi);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << solve(n)<< '\n';
    }
    return 0;
}
