#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define all(x) x.begin(), x.end()
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e5;
vll phi(MAXN + 1);
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void precompute() {
    for(int i = 2;i <= MAXN; i++) {
        if(phi[i] == i){
            for(int j = i;j <= MAXN;j+=i){
                phi[j] = phi[j] - phi[j]/i;// n*(1 - 1/p)
            }
        }
    }
}

int main() {
    setIO();
    iota(all(phi), 0);
    precompute();
    for(int i = 1;i <= MAXN;i++){
        phi[i] = phi[i] + phi[i - 1];
    }
    int t;
    cin >> t;
    for(int i = 0;i < t;i++){
        int n;
        cin >> n;
        cout << "Case " << i + 1 << ": "<< (1LL*n*(n+1)/2) - phi[n] << '\n';
    }
    return 0;
}
