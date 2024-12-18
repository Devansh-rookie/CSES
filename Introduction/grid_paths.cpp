// // // #include <iostream>
// // // #include <fstream>
// // // #include <sstream>
// // // #include <iomanip>
// // // #include <string>  
// // // #include <vector>
// // // #include <list>        
// // // #include <set> 
// // // #include <map>    
// // // #include <queue> 
// // // #include <stack>
// // // #include <algorithm>  
// // // #include <cmath> 
// // // #include <ctime> 
// // // #include <cstdlib>
// // // #include <cstring> 
// // // #include <cctype> 
// // // #include <cassert>
// // // #include <exception>   
// // // #include <functional>
// // // #include <iterator>
// // // #include <limits>  
// // // #include <locale>   
// // // #include <numeric>  
// // // #include <random> 
// // // #include <stdexcept> 
// // // #include <typeinfo> 
// // // #include <utility>
// // // using namespace std;
// // // int n;
// // // int dx[] = {1, -1, 0, 0};
// // // int dy[] = {0, 0, -1, 1};
// // // char moveChar[] = {'D', 'U', 'L', 'R'};
// // // bool isValid(int x, int y, vector<vector<bool>> &vis) {
// // //     return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y];
// // // }

// // // int solve(int i, int j, string &s, int index, vector<vector<vector<int>>> &dp, vector<vector<bool>> &vis){
// // //     int N = n;
// // //     int x = i;
// // //     int y = j;
// // //     // if(i == n - 1 && j == 0 && index == 48){
// // //     //     return 1;
// // //     // }
// // //     // if(i >= n || j >= n || j <0 || i < 0 || index == 48|| vis[i][j]) return 0;
// // //     if (index == 48) {
// // //         return (x == N - 1 && y == 0) ? 1 : 0;
// // //     }

// // //     // If already reached the target but not at the last step, prune
// // //     if (x == N - 1 && y == 0) {
// // //         return 0;
// // //     }

// // //      if ((x > 0 && vis[x - 1][y]) + (x < N - 1 && vis[x + 1][y]) +
// // //         (y > 0 && vis[x][y - 1]) + (y < N - 1 && vis[x][y + 1]) == 4) {
// // //         return 0;
// // //     }
// // //     if(dp[i][j][index]!= -1) return dp[i][j][index];
// // //     vis[i][j] = true;
// // //     int ans = 0;
// // //     if(s[index] != '?'){
// // //         // if(s[index] == 'D'){
// // //         //     int nx = i + dx[0];
// // //         //     int ny = j + dy[0];
// // //         //     if(isValid(nx, ny, vis)) ans += solve(nx, ny, s, index+1, dp, vis);
// // //         // }
// // //         // else if(s[index] == 'L'){
// // //         //     int nx = i + dx[2];
// // //         //     int ny = j + dy[2];
// // //         //     if(isValid(nx, ny, vis)) ans += solve(nx, ny,s, index+1, dp, vis);
// // //         // }
// // //         // else if(s[index] == 'U'){
// // //         //     int nx = i + dx[1];
// // //         //     int ny = j + dy[1];
// // //         //     if(isValid(nx, ny, vis)) ans += solve(nx, ny, s, index+1, dp, vis);
// // //         // }
// // //         // else{ // 'R'
// // //         //     int nx = i + dx[3];
// // //         //     int ny = j + dy[3];
// // //         //     if(isValid(nx, ny, vis)) ans += solve(nx, ny, s, index+1, dp, vis);
// // //         // }
// // //         for (int m = 0; m < 4; m++) {
// // //             if (s[index] == moveChar[m]) {
// // //                 int nx = i + dx[m], ny = j + dy[m];
// // //                 if (isValid(nx, ny, vis)) {
// // //                     ans += solve(nx, ny, s, index+1, dp, vis);
// // //                 }
// // //             }
// // //         }

// // //     }
// // //     else{
// // //         // vector<pair<int ,int>> paths = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
// // //         // for(auto node: paths){
// // //         //     int x = node.first;
// // //         //     int y = node.second;
// // //         //     ans += solve(i+x, j+y, s, index+1, dp, vis);
// // //         // }
// // //         for (int m = 0; m < 4; m++) {
// // //             int nx = i + dx[m], ny = j + dy[m];
// // //             if (isValid(nx, ny, vis)) {
// // //                 ans += solve(nx, ny, s, index+1, dp, vis);
// // //             }
// // //         }
// // //     }
// // //     vis[i][j] = false;
// // //     return dp[i][j][index] = ans;
// // // }

// // // int main()
// // // {
// // //     string s;
// // //     cin >> s;
// // //     n = 7;

// // //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(48, -1)));
// // //     vector<vector<bool>> vis(n, vector<bool> (n, false));
// // //     cout << solve(0, 0, s, 0, dp, vis) << endl;
// // //     return 0;
// // // }


// // #include <iostream>
// // #include <vector>
// // #include <string>

// // using namespace std;

// // const int N = 7; // Grid size
// // const int STEPS = 48; // Total number of steps
// // string description; // Input description
// // bool visited[N][N]; // Visited grid

// // // Moves: Down, Up, Left, Right
// // int dx[] = {1, -1, 0, 0};
// // int dy[] = {0, 0, -1, 1};
// // char moveChar[] = {'D', 'U', 'L', 'R'};

// // bool isValid(int x, int y) {
// //     return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y];
// // }

// // int dfs(int x, int y, int step, vector<vector<vector<int>>>&dp) {
// //     // Base case: reached step limit and at target position
// //     if (step == STEPS) {
// //         return (x == N - 1 && y == 0) ? 1 : 0;
// //     }

// //     // If already reached the target but not at the last step, prune
// //     if (x == N - 1 && y == 0) {
// //         return 0;
// //     }

// //     // Check if surrounded (early pruning)
// //     if ((x > 0 && visited[x - 1][y]) + (x < N - 1 && visited[x + 1][y]) +
// //         (y > 0 && visited[x][y - 1]) + (y < N - 1 && visited[x][y + 1]) == 4) {
// //         return 0;
// //     }
// //     // if(dp[x][y][step]!= -1) return dp[x][y][step];

// //     int paths = 0;
// //     visited[x][y] = true;

// //     if (description[step] == '?') {
// //         // Try all possible moves
// //         for (int i = 0; i < 4; i++) {
// //             int nx = x + dx[i], ny = y + dy[i];
// //             if (isValid(nx, ny)) {
// //                 paths += dfs(nx, ny, step + 1, dp);
// //             }
// //         }
// //     } else {
// //         // Follow the fixed move
// //         for (int i = 0; i < 4; i++) {
// //             if (description[step] == moveChar[i]) {
// //                 int nx = x + dx[i], ny = y + dy[i];
// //                 if (isValid(nx, ny)) {
// //                     paths += dfs(nx, ny, step + 1, dp);
// //                 }
// //             }
// //         }
// //     }

// //     visited[x][y] = false;
// //     // return dp[x][y][step] = paths;
// //     return paths;
// // }

// // int main() {
// //     cin >> description;

// //     // Initialize the visited grid
// //     for (int i = 0; i < N; i++) {
// //         for (int j = 0; j < N; j++) {
// //             visited[i][j] = false;
// //         }
// //     }
// //     int n = N;
// //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(48, -1)));

// //     // Start DFS from the top-left corner

// //     cout << dfs(0, 0, 0, dp) << endl;
// //     return 0;
// // }


// #include <iostream>
// #include <string>
// #include <cstring>

// using namespace std;

// const int N = 7; // Grid size
// const int STEPS = 48; // Total number of steps
// string description; // Input description
// int dp[N][N][STEPS]; // DP table
// bool visited[N][N]; // Visited grid

// // Moves: Down, Up, Left, Right
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, -1, 1};
// char moveChar[] = {'D', 'U', 'L', 'R'};

// bool isValid(int x, int y) {
//     return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y];
// }

// int dfs(int x, int y, int step) {
//     // Base case: reached step limit and at target position
//     if (step == STEPS) {
//         return (x == N - 1 && y == 0) ? 1 : 0;
//     }

//     // If already reached the target but not at the last step, prune
//     if (x == N - 1 && y == 0) {
//         return 0;
//     }

//     // If already calculated, return the result
//     if (dp[x][y][step] != -1) {
//         return dp[x][y][step];
//     }

//     int paths = 0;
//     visited[x][y] = true;

//     if (description[step] == '?') {
//         // Try all possible moves
//         for (int i = 0; i < 4; i++) {
//             int nx = x + dx[i], ny = y + dy[i];
//             if (isValid(nx, ny)) {
//                 paths += dfs(nx, ny, step + 1);
//             }
//         }
//     } else {
//         // Follow the fixed move
//         for (int i = 0; i < 4; i++) {
//             if (description[step] == moveChar[i]) {
//                 int nx = x + dx[i], ny = y + dy[i];
//                 if (isValid(nx, ny)) {
//                     paths += dfs(nx, ny, step + 1);
//                 }
//             }
//         }
//     }

//     visited[x][y] = false;
//     return dp[x][y][step] = paths;
// }

// int main() {
//     cin >> description;

//     // Initialize DP table and visited grid
//     memset(dp, -1, sizeof(dp));
//     memset(visited, false, sizeof(visited));

//     // Start DFS from the top-left corner
//     cout << dfs(0, 0, 0) << endl;

//     return 0;
// }


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N = 7; // Grid size
const int STEPS = 48; // Total number of steps
string description; // Input description
int dp[N][N][STEPS]; // DP table
bool visited[N][N]; // Visited grid

// Moves: Down, Up, Left, Right
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
char moveChar[] = {'D', 'U', 'L', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y];
}

int dfs(int x, int y, int step) {
    // Base case: reached step limit and at target position
    if (step == STEPS) {
        return (x == N - 1 && y == 0) ? 1 : 0;
    }

    // If already calculated, return the result
    if (dp[x][y][step] != -1) {
        return dp[x][y][step];
    }

    int paths = 0;
    visited[x][y] = true;

    if (description[step] == '?') {
        // Try all possible moves
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny)) {
                paths += dfs(nx, ny, step + 1);
            }
        }
    } else {
        // Follow the fixed move
        for (int i = 0; i < 4; i++) {
            if (description[step] == moveChar[i]) {
                int nx = x + dx[i], ny = y + dy[i];
                if (isValid(nx, ny)) {
                    paths += dfs(nx, ny, step + 1);
                }
            }
        }
    }

    visited[x][y] = false;
    return dp[x][y][step] = paths;
}

int main() {
    cin >> description;

    // Initialize DP table and visited grid
    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));

    // Start DFS from the top-left corner
    cout << dfs(0, 0, 0) << endl;

    return 0;
}
