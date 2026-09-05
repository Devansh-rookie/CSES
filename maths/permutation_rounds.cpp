#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 2e5;

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

ll lcm(vi &cycle_lengths){
    sieve();
    vi maxPower(MAXN + 1, 0);

    for(int num: cycle_lengths){
        while(num > 1){
            int some_num = spf[num];
            int c = 0;
            while(num % some_num == 0) num /= some_num, c++;
            maxPower[some_num] = max(maxPower[some_num], c);
        }
    }

    ll ans = 1;
    for(int prime = 2;prime <= MAXN; prime++){
        for(int power = 1; power <= maxPower[prime]; power++){
            ans = (ans * prime)%MOD;
        }
    }
    return ans;
}

int main() {
    // setIO("check");

    int n;
    cin >> n;
    vi p(n + 1, 0);
    vector<bool> visited(n + 1, false);
    for(int i = 0;i < n;i++){
        cin >> p[i + 1];
    }
    vi cycle_lengths;
    for(int i = 1;i <= n;i++){
        if(visited[i]) continue;

        int curr = i;
        int len = 0;
        while(!visited[curr]){
            visited[curr] = true;
            curr = p[curr];
            len++;
        }
        cycle_lengths.pb(len);
    }

    cout << lcm(cycle_lengths) << '\n';
    return 0;
}
