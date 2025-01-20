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

vector<vector<char>> arr;
vector<vector<int>> vis;
vector<pii> paths = {{0, 1},{1, 0},{-1, 0},{0, -1}};
int n, m;

bool check(int x, int y){
    return !(x >= n || y >= m || x < 0 || y < 0);
}

void dfs(int i, int j){
    if(vis[i][j] || arr[i][j] == '#'  || !check(i, j)) return;
    vis[i][j] = 1;
    for(auto [cx, cy] : paths){
        int nx , ny;
        nx = i + cx;
        ny = j + cy;
        if(!check(nx, ny)) continue;
        dfs(nx, ny);
    }
}

void solve(){
    cin >> n >>  m;
    arr.assign(n, vector<char> (m));
    vis.assign(n, vector<int> (m, 0));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }
    }

    // if there is a bad guy right next to a good guy then its impossible to make such a grid

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] == 'B'){
                for(auto [cx, cy] : paths){
                    int nx , ny;
                    nx = i + cx;
                    ny = j + cy;
                    if(!check(nx, ny)) continue;
                    if(arr[nx][ny] == 'G'){
                        cout << "NO\n";
                        return;
                    }
                    else if(arr[nx][ny] == '.'){
                        arr[nx][ny] = '#';
                    }
                }
            }
        }
    }
    if (arr[n-1][m-1] != '#') {
        dfs(n-1, m - 1);
    }// check from the end where all you can go then go there
    else{
        // exit is blocked G means NO
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(arr[i][j] == 'G'){
                    cout << "NO\n";
                    return;
                }
            }
        }
        cout << "YES\n";
        return;
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] == 'G' && !vis[i][j]){
                cout << "NO\n";
                return;
            }
            if(arr[i][j] == 'B' && vis[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    setIO("check/check");

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}