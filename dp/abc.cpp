// #include <bits/stdc++.h>
// using namespace std;

// void printResult(int n, vector<vector<int>> arr)
// {
//     const int INF = 1e9;
//     vector<int> totalDist(n, 0);          // totalDist[i] = Σ distance(i, j)

//     // --- run BFS from every city -------------------------------------------
//     for (int src = 0; src < n; ++src)
//     {
//         vector<int> dist(n, INF);
//         queue<int> q;

//         dist[src] = 0;
//         q.push(src);

//         while (!q.empty())
//         {
//             int u = q.front(); q.pop();
//             for (int v = 0; v < n; ++v)
//             {
//                 if (arr[u][v] && dist[v] == INF)   // road exists & not visited
//                 {
//                     dist[v] = dist[u] + 1;
//                     q.push(v);
//                 }
//             }
//         }
//         // accumulate distances for this source
//         for (int v = 0; v < n; ++v) totalDist[src] += dist[v];
//     }

//     // --- identify highest-centrality cities --------------------------------
//     int best = *min_element(totalDist.begin(), totalDist.end());

//     bool first = true;
//     for (int i = 0; i < n; ++i)
//         if (totalDist[i] == best)
//         {
//             if (!first) cout << ' ';
//             cout << i;
//             first = false;
//         }
//     cout << '\n';
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     if (!(cin >> n)) return 0;

//     vector<vector<int>> arr(n, vector<int>(n));
//     for (int i = 0; i < n; ++i)
//         for (int j = 0; j < n; ++j)
//             cin >> arr[i][j];

//     printResult(n, arr);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

bool hasUniqueDigits(const string& s) {
    bool seen[10] = {false};
    for (char c : s) {
        int d = c - '0';
        if (seen[d]) return false;
        seen[d] = true;
    }
    return true;
}

string buildReply(const string& guess, const string& cand) {
    string res(5, 'B');
    for (int i = 0; i < 5; ++i) {
        if (cand[i] == guess[i]) {
            res[i] = 'G';
        } else if (cand.find(guess[i]) != string::npos) {
            res[i] = 'Y';
        }
    }
    return res;
}

vector<int> printPossibleResults(int guess, const string& response) {
    string g = to_string(guess);
    vector<int> ans;

    for (int num = 10000; num <= 99999; ++num) {
        string s = to_string(num);
        if (s[0] == '0' || !hasUniqueDigits(s)) continue;      // rule: no leading 0, no repeats[1]
        if (buildReply(g, s) == response) ans.push_back(num);
    }
    return ans;
}

int main() {
    int guess;
    string response;
    cin >> guess;
    cin.ignore();              // consume end-of-line after the number
    getline(cin, response);

    vector<int> res = printPossibleResults(guess, response);

    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i + 1 != res.size()) cout << ' ';
    }
    return 0;
}
