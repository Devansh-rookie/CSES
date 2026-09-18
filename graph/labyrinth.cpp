#include<bits/stdc++.h>
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

vi dx = {0, 1, -1, 0};
vi dy = {1, 0, 0, -1};
string mapping = "RDUL";
int main(){
    setIO("");
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pii start, end;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') start = {i, j};
            if(grid[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vvi prev(n, vi(m, INT_MAX));
    queue<pii> q;
    q.push(start);
    vis[start.first][start.second] = true;
    while(!q.empty()){
        auto const [r, c] = q.front();
        q.pop();
        for(int d = 0;d < 4;d++){
            int nx = r + dx[d];
            int ny = c + dy[d];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] != '#'){
                vis[nx][ny] = true;
                q.push({nx, ny});
                prev[nx][ny] = d;
            }
        }
    }

    if(vis[end.first][end.second]){
        cout << "YES\n";
        vector<int> ans;
        while(end != start){
            int direction = prev[end.first][end.second];
            ans.push_back(direction);
            end.first -= dx[direction];
            end.second -= dy[direction];
        }
        reverse(all(ans));
        cout << ans.size() << '\n';
        for(int i: ans){
            cout << mapping[i];
        }
        cout << '\n';
        return 0;
    }
    cout << "NO\n";
    return 0;
}
