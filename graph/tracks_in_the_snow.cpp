#include<bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
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

vi dx = {0, 1, -1, 0};
vi dy = {1, 0, 0, -1};

void flood_fill(vector<vector<char>> &grid, vvi &comp, int i, int j, int num_comp){
    int n = grid.size();
    int m = grid[0].size();
    queue<pii> q;
    q.push({i, j});
    char ch = grid[i][j];
    comp[i][j] = num_comp;
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int d = 0;d < 4;d++){
            int nx = r + dx[d];
            int ny = c + dy[d];
            if(nx < n && ny < m && nx >= 0 && ny >= 0 && ch == grid[nx][ny] && comp[nx][ny] == INT_MAX){
                comp[nx][ny] = num_comp;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    setIO("check");
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            cin >> grid[i][j];
        }
    }
    vvi comp(H, vi(W, INT_MAX));
    int num_comp = 0;
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if(grid[i][j] != '.' && comp[i][j] == INT_MAX){
                num_comp++;
                flood_fill(grid, comp, i, j, num_comp);
            }
        }
    }
    vvi adj(num_comp + 1);
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if(comp[i][j] == INT_MAX) continue;
            for(int d = 0;d < 4;d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx < H && ny < W && nx >= 0 && ny >= 0 && comp[nx][ny] != INT_MAX && comp[i][j] != comp[nx][ny]){
                    adj[comp[i][j]].pb(comp[nx][ny]);
                    adj[comp[nx][ny]].pb(comp[i][j]);
                }
            }
        }
    }

    queue<int> q;
    q.push(1);
    vi dist(num_comp + 1, INT_MAX);
    int ans = 0;
    dist[1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int nei: adj[node]){
            if(dist[nei] == INT_MAX){
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }
    for(int i: dist){
        if(i != INT_MAX) ans = max(ans, i);
    }
    cout << ans + 1 << '\n';
    return 0;
}
