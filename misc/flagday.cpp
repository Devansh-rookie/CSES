#include<bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    // setIO("check");

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> ans(n + 1, 0);

    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;

        // Arc consistency 3 way like we leant in AI

        set<int>temp;
        set<int>temp2;
        temp.insert(ans[a]);
        temp.insert(ans[b]);
        temp.insert(ans[c]);

        for(int i = 1;i <= 3;i++) if(temp.count(i) == 0) temp2.insert(i);

        if(!ans[a]){
            if(temp2.size() != 0){
                ans[a] = *temp2.begin();
                temp2.erase(temp2.begin());
            }
        }
        if(!ans[b]){
            if(temp2.size() != 0){
                ans[b] = *temp2.begin();
                temp2.erase(temp2.begin());
            }
        }
        if(!ans[c]){
            if(temp2.size() != 0){
                ans[c] = *temp2.begin();
                temp2.erase(temp2.begin());
            }
        }
    }


    for(int i = 1;i <= n;i++) cout << ans[i] << " ";

    return 0;
}
