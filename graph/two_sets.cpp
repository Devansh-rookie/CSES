#include<bits/stdc++.h>
#include <climits>
#include <vector>
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
map<int, int> m;
class DSU {
public:
    vector<int> parent;
    vector<int> size;
    vector<bool> exist;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        exist.resize(n, false);
        iota(parent.begin(), parent.end(), 0);
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }

    void uniteSize(int n1, int n2) {
        n1 = m[n1];
        n2 = m[n2];
        int u = findPar(n1);
        int v = findPar(n2);
        if (u == v) return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }

    void add(int node){
        node = m[node];
        exist[node] = true;
    }
};

int main(){
    setIO("check");
    int n, a, b;
    cin >> n >> a >> b;
    vi arr(n);
    for(int i = 0;i < n;i++){cin >> arr[i]; m[arr[i]] = i;}

    DSU ds(n);
    vi answer(n, INT_MAX);
    for(int i = 0;i < n;i++){
        if(m.count(a - arr[i])){
            ds.uniteSize(arr[i], a - arr[i]);
        }
        if(m.count(b - arr[i])){
            ds.uniteSize(arr[i], b - arr[i]);
        }
        if(!m.count(a - arr[i]) && !m.count(b - arr[i])){
            cout << "NO\n";
            return 0;
        }
    }

    vector<bool> amust(n, false), bmust(n, false);
    for(int i = 0;i < n;i++){
        int x = arr[i];
        bool ifa = m.count(a - x);
        bool ifb = m.count(b - x);
        int root = ds.findPar(i);
        if(ifa && !ifb){
            amust[root] = true;
        }
        if(!ifa && ifb){
            bmust[root] = true;
        }
    }

    for(int i = 0;i < n;i++){
        if(amust[i] && bmust[i]){
            cout << "NO\n";
            return 0;
        }
    }

    for(int i = 0;i < n;i++){
        int root = ds.findPar(i);
        if(amust[root]) answer[i] = 0;
        else if(bmust[root]) answer[i] = 1;
        else answer[i] = 0;
    }
    cout << "YES\n";
    for(int i: answer){
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
