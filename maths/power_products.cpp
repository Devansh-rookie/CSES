#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e5;

vi spf(MAXN + 1);

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

int main() {
    // setIO("check");

    int n, k;
    cin >> n >> k;
    vi cnt(MAXN + 1, 0);
    ll ans = 0;
    sieve();
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        ll has = 1;
        ll needs = 1;
        bool over = false;
        while(x > 1){
            int p = spf[x];
            int power = 0;
            while(x%p == 0){
                power++;
                x/=p;
            }
            int r = power%k;
            if(r > 0){
                for(int j = 0;j < r;j++) has *= p;
                int need_exp = k - r;
                for(int j = 0;j < need_exp;j++){
                    if(!over){
                        if(needs > MAXN / p){
                            over = true;
                        }
                        else{
                            needs *= p;
                        }
                    }
                }
            }
        }
        if(!over && needs <= MAXN){
            ans += cnt[needs];
        }
        cnt[has]++;
    }

    cout << ans << '\n';

    return 0;
}
