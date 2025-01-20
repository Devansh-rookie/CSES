#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int ans = 0;
int n, m;
vector<vector<int>> arr;
vector<vector<int>> vis;
vector<pii> paths = {{0, 1},{1, 0},{-1, 0},{0, -1}};


bool check(int x, int y){
    return !(x >= n || y >= m || x < 0 || y < 0);
}

void dfs(int i, int j){
    vis[i][j] = 1;
    for(auto const &[cx, cy] : paths){
        int nx , ny;
        nx = i + cx;
        ny = j + cy;
        if(!check(nx, ny) || vis[nx][ny] || !arr[i][j]) continue;
        dfs(nx, ny);
    }
}

int main() {
    // setIO("check");
    cin >> n >> m;
    arr.resize(n, vector<int>(m, 0));
    vis.resize(n, vector<int>(m, 0));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            char val;
            cin >> val;

            if(val == '.') arr[i][j] = 1;
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] && !vis[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}