#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int calculateMex(const unordered_set<int>& values) {
    int mex = 0;
    while (values.find(mex) != values.end()) {
        ++mex;
    }
    return mex;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<vector<int>> adj(n + 1);
        for(int i = 1; i <= n; ++i){
            adj[i].push_back(i == 1 ? n : i - 1);
            adj[i].push_back(i == n ? 1 : i + 1); 
        }
        adj[x].push_back(y); 
        adj[y].push_back(x);

        vector<int> result(n + 1, -1);
        for(int i = 1; i <= n; ++i){
            unordered_set<int> neighborValues;
            for(int neighbor : adj[i]) {
                if(result[neighbor] != -1){
                    neighborValues.insert(result[neighbor]);
                }
            }
            result[i] = calculateMex(neighborValues);
        }
        for(int i = 1; i <= n; ++i){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
