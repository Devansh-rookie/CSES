#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e6;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void precompute(vll &phi) {
    for(int i = 2;i <= MAXN; i++) {
        if(phi[i] == i){
            for(int j = i;j <= MAXN;j+=i){
                phi[j] = phi[j] - phi[j]/i;// n*(1 - 1/p)
            }
        }
    }
}

int main() {
    // setIO("check");

    vll phi(1e6 + 1);
    vll f(1e6 + 1);
    vll answer(1e6 + 1);
    iota(all(phi), 0);
    precompute(phi);
    for(int i = 1;i <= MAXN;i++){
        for(int j = i;j <= MAXN;j+=i){
            f[j] += i*phi[j/i];
        }
    }

    for(int i = 1;i <= MAXN;i++){
        answer[i] = answer[i - 1] + f[i] - i;
    }
    while (true) {
        int n;
        cin >> n;
        if(n == 0) return 0;
        cout << answer[n] << '\n';
    }
    return 0;
}
