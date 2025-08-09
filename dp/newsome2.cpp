// // #include <bits/stdc++.h>
// // using namespace std;
// // // void setIO(string name = "") {
// // //     ios_base::sync_with_stdio(0);
// // //     cin.tie(0);
// // //     if (name.size()) {
// // //         freopen((name + ".in").c_str(), "r", stdin);
// // //         freopen((name + ".out").c_str(), "w", stdout);
// // //     }
// // // }

// // int numberOfFlowers(int M, int N, vector<vector<int>> A) {
// //     int res = 0;

// //     const int dr[4] = {-1, 1, 0, 0};
// //     const int dc[4] = {0, 0, -1, 1};

// //     vector<vector<int>> compId(M, vector<int>(N, -1));
// //     vector<int> compVal, compSize;
// //     vector<pair<int, int>> edges;

// //     for (int r = 0; r < M; r++) {
// //         for (int c = 0; c < N; c++) {
// //             if (compId[r][c] == -1) {
// //                 int id = compVal.size();
// //                 int val = A[r][c];
// //                 int cnt = 0;
// //                 queue<pair<int, int>> q;
// //                 q.push({r, c});
// //                 compId[r][c] = id;

// //                 while (!q.empty()) {
// //                     auto [cr, cc] = q.front(); q.pop();
// //                     cnt++;
// //                     for (int k = 0; k < 4; k++) {
// //                         int nr = cr + dr[k], nc = cc + dc[k];
// //                         if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
// //                         if (A[nr][nc] == val) {
// //                             if (compId[nr][nc] == -1) {
// //                                 compId[nr][nc] = id;
// //                                 q.push({nr, nc});
// //                             }
// //                         } else {
// //                             edges.push_back({r * N + c, nr * N + nc});
// //                         }
// //                     }
// //                 }

// //                 compVal.push_back(val);
// //                 compSize.push_back(cnt);
// //             }
// //         }
// //     }

// //     int compCnt = compVal.size();
// //     vector<vector<int>> adj(compCnt);

// //     for (auto edge : edges) {
// //         int r1 = edge.first / N, c1 = edge.first % N;
// //         int r2 = edge.second / N, c2 = edge.second % N;
// //         int u = compId[r1][c1];
// //         int v = compId[r2][c2];
// //         if (u == v) continue;
// //         adj[u].push_back(v);
// //         adj[v].push_back(u);
// //     }

// //     unordered_map<long long, int> pairToIdx;
// //     vector<int> pairA, pairB;

// //     auto getPairIndex = [&](int a, int b) {
// //         if (a > b) swap(a, b);
// //         long long key = ((long long)a << 32) | (unsigned int)b;
// //         if (pairToIdx.count(key)) return pairToIdx[key];
// //         int id = pairA.size();
// //         pairToIdx[key] = id;
// //         pairA.push_back(a);
// //         pairB.push_back(b);
// //         return id;
// //     };

// //     vector<pair<int, int>> compEdges;
// //     for (int u = 0; u < compCnt; u++) {
// //         for (int v : adj[u]) {
// //             if (u < v) compEdges.push_back({u, v});
// //         }
// //     }

// //     vector<int> edgePairIdx;
// //     for (auto [u, v] : compEdges) {
// //         edgePairIdx.push_back(getPairIndex(compVal[u], compVal[v]));
// //     }

// //     vector<int> lastSeen(compCnt, -1);
// //     res = *max_element(compSize.begin(), compSize.end());

// //     queue<int> q;
// //     for (int e = 0; e < compEdges.size(); e++) {
// //         int u = compEdges[e].first, v = compEdges[e].second;
// //         int pid = edgePairIdx[e];
// //         int t1 = pairA[pid], t2 = pairB[pid];

// //         auto bfs = [&](int start) {
// //             int area = 0;
// //             q.push(start);
// //             lastSeen[start] = pid;
// //             while (!q.empty()) {
// //                 int cur = q.front(); q.pop();
// //                 area += compSize[cur];
// //                 for (int nb : adj[cur]) {
// //                     if (lastSeen[nb] == pid) continue;
// //                     int val = compVal[nb];
// //                     if (val == t1 || val == t2) {
// //                         lastSeen[nb] = pid;
// //                         q.push(nb);
// //                     }
// //                 }
// //             }
// //             return area;
// //         };

// //         if (lastSeen[u] != pid) res = max(res, bfs(u));
// //         if (lastSeen[v] != pid) res = max(res, bfs(v));
// //     }

// //     return res;
// // }

// // int main() {
// //     // setIO("check");
// //     int M, N;
// //     cin >> M >> N;
// //     vector<vector<int>> A(M, vector<int>(N));
// //     for (int i = 0; i < M; i++)
// //         for (int j = 0; j < N; j++)
// //             cin >> A[i][j];

// //     cout << numberOfFlowers(M, N, A);
// //     return 0;
// // }


// #include <bits/stdc++.h>
// using namespace std;

// int maxPatchArea(int rows, int cols, vector<vector<int>> grid) {
//     int maxArea = 0;

//     const int dRow[4] = {-1, 1, 0, 0};
//     const int dCol[4] = {0, 0, -1, 1};

//     vector<vector<int>> regionId(rows, vector<int>(cols, -1));
//     vector<int> regionVal, regionSize;
//     vector<pair<int, int>> rawEdges;

//     for (int r = 0; r < rows; ++r) {
//         for (int c = 0; c < cols; ++c) {
//             if (regionId[r][c] == -1) {
//                 int id = regionVal.size();
//                 int val = grid[r][c];
//                 int size = 0;

//                 queue<pair<int, int>> q;
//                 q.push({r, c});
//                 regionId[r][c] = id;

//                 while (!q.empty()) {
//                     auto [curR, curC] = q.front(); q.pop();
//                     size++;
//                     for (int d = 0; d < 4; ++d) {
//                         int newR = curR + dRow[d];
//                         int newC = curC + dCol[d];
//                         if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) continue;

//                         if (grid[newR][newC] == val) {
//                             if (regionId[newR][newC] == -1) {
//                                 regionId[newR][newC] = id;
//                                 q.push({newR, newC});
//                             }
//                         } else {
//                             rawEdges.push_back({r * cols + c, newR * cols + newC});
//                         }
//                     }
//                 }

//                 regionVal.push_back(val);
//                 regionSize.push_back(size);
//             }
//         }
//     }

//     int regionCount = regionVal.size();
//     vector<vector<int>> graph(regionCount);

//     for (auto e : rawEdges) {
//         int r1 = e.first / cols, c1 = e.first % cols;
//         int r2 = e.second / cols, c2 = e.second % cols;
//         int u = regionId[r1][c1], v = regionId[r2][c2];
//         if (u == v) continue;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }

//     unordered_map<long long, int> pairIndexMap;
//     vector<int> labelA, labelB;

//     auto getIndex = [&](int a, int b) {
//         if (a > b) swap(a, b);
//         long long key = ((long long)a << 32) | (unsigned int)b;
//         if (pairIndexMap.count(key)) return pairIndexMap[key];
//         int idx = labelA.size();
//         pairIndexMap[key] = idx;
//         labelA.push_back(a);
//         labelB.push_back(b);
//         return idx;
//     };

//     vector<pair<int, int>> condensedEdges;
//     for (int u = 0; u < regionCount; ++u) {
//         for (int v : graph[u]) {
//             if (u < v) condensedEdges.push_back({u, v});
//         }
//     }

//     vector<int> edgeTypeId;
//     for (auto [u, v] : condensedEdges) {
//         edgeTypeId.push_back(getIndex(regionVal[u], regionVal[v]));
//     }

//     vector<int> lastSeen(regionCount, -1);
//     maxArea = *max_element(regionSize.begin(), regionSize.end());

//     queue<int> bfsQueue;
//     for (int i = 0; i < condensedEdges.size(); ++i) {
//         int u = condensedEdges[i].first, v = condensedEdges[i].second;
//         int pairId = edgeTypeId[i];
//         int type1 = labelA[pairId], type2 = labelB[pairId];

//         auto bfs = [&](int start) {
//             int total = 0;
//             bfsQueue.push(start);
//             lastSeen[start] = pairId;
//             while (!bfsQueue.empty()) {
//                 int cur = bfsQueue.front(); bfsQueue.pop();
//                 total += regionSize[cur];
//                 for (int nb : graph[cur]) {
//                     if (lastSeen[nb] == pairId) continue;
//                     int val = regionVal[nb];
//                     if (val == type1 || val == type2) {
//                         lastSeen[nb] = pairId;
//                         bfsQueue.push(nb);
//                     }
//                 }
//             }
//             return total;
//         };

//         if (lastSeen[u] != pairId) maxArea = max(maxArea, bfs(u));
//         if (lastSeen[v] != pairId) maxArea = max(maxArea, bfs(v));
//     }

//     return maxArea;
// }

// int main() {
//     int R, C;
//     cin >> R >> C;
//     vector<vector<int>> matrix(R, vector<int>(C));
//     for (int i = 0; i < R; ++i)
//         for (int j = 0; j < C; ++j)
//             cin >> matrix[i][j];

//     cout << maxPatchArea(R, C, matrix);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int a, b;
vector<vector<int>> g;
vector<vector<bool>> v;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < a && y >= 0 && y < b;
}

int bfs(int sx, int sy, int f1, int f2) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    v[sx][sy] = 1;
    int c = 1;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny) && !v[nx][ny] && (g[nx][ny] == f1 || g[nx][ny] == f2)) {
                v[nx][ny] = 1;
                q.push({nx, ny});
                c++;
            }
        }
    }
    return c;
}

int numberOfFlowers(int M, int N, vector<vector<int>> A) {
    a = M;
    b = N;
    g = A;

    set<int> s;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            s.insert(g[i][j]);

    vector<int> f(s.begin(), s.end());
    int ma = 0;
    for (int i = 0; i < f.size(); i++) {
        for (int j = i; j < f.size(); j++) {
            v.assign(a, vector<bool>(b, 0));
            for (int x = 0; x < a; x++) {
                for (int y = 0; y < b; y++) {
                    if (!v[x][y] && (g[x][y] == f[i] || g[x][y] == f[j])) {
                        ma = max(ma, bfs(x, y, f[i], f[j]));
                    }
                }
            }
        }
    }

    return ma;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> A(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    cout << numberOfFlowers(M, N, A);
    return 0;
}
