// #include<bits/stdc++.h>
// using namespace std;
// using vi = vector<int>;
// using vvi = vector<vector<int>>;
// using pii = pair<int, int>;

// void setIO(string name = "") {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     if (name.size()) {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

// vector<pii> changes = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

// bool check(int i, int j, int n){
//     return !(i >= n || j>= n|| i< 0 || j < 0);
// }

// void dfs(int i, int j,vvi & grid, vvi &visited){
//     int n = grid.size();
//     visited[i][j] = 1;
//     for(auto const&[xv, xy] : changes){
//         int nx = xv + i;
//         int ny = xy + j;

//         if(check(nx, ny, n) && !visited[nx][ny] && grid[nx][ny] == 1){
//             dfs(nx, ny, grid, visited);
//         }
//     }
// }

// int solve(vvi &grid1, vvi&grid2){
//     int n = grid1.size();

//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < n;j++){

//         }
//     }
// }

// int main() {
//     setIO();



//     return 0;
// }

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int rows, cols;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<int>> &grid, int x, int y, set<pair<int, int>> &region, int baseX, int baseY) {
    if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0)
        return;

    grid[x][y] = 0;

    region.insert({x - baseX, y - baseY});

    for (auto &[dx, dy] : directions) {
        dfs(grid, x + dx, y + dy, region, baseX, baseY);
    }
}

vector<set<pair<int, int>>> findRegions(vector<vector<int>> &grid) {
    vector<set<pair<int, int>>> regions;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                set<pair<int, int>> region;
                dfs(grid, i, j, region, i, j);
                regions.push_back(region);
            }
        }
    }
    return regions;
}

int countMatchingRegions(vector<vector<int>> grid1, vector<vector<int>> grid2) {
    auto regions1 = findRegions(grid1);
    auto regions2 = findRegions(grid2);

    int matches = 0;
    for (auto &r1 : regions1) {
        for (auto &r2 : regions2) {
            if (r1 == r2) {  
                matches++;
                break; 
            }
        }
    }
    return matches;
}

// Driver Code
int main() {
    vector<vector<int>> grid1 = {
        {1, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    };

    vector<vector<int>> grid2 = {
        {1, 1, 1},
        {1, 0, 0},
        {1, 0, 1}
    };

    rows = grid1.size();
    cols = grid1[0].size();

    cout << "Matching Regions: " << countMatchingRegions(grid1, grid2) << endl;
    return 0;
}