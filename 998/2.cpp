#include<bits/stdc++.h>
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
    int t;
    cin >> t;
    while(t--){
        outer:
        if(t<0) break;
        int n,m;
        cin >> n >> m;

        vector<vector<int>> cards(n, vector<int> (m, 0));

        for(int i =0;i < n;i++){
            for(int j = 0;j < m;j++){
                cin >> cards[i][j];
            }
        }

        for(int i =0;i < n;i++){
            sort(cards[i].begin(), cards[i].end());
        }

        vector<int> p(n, 0);
        vector<pair<int, int>> temp;

        for(int i = 0;i < n;i++){
            temp.emplace_back(cards[i][0], i);
        }

        sort(temp.begin(), temp.end());

        for(int i = 0;i < n;i++){
            p[i] = temp[i].second;
        }

        // bool flag = true;
        int maxx = 0;
        for(int j = 0;j < m;j++){
            vector<pair<int, int>> ti;
            for(int i = 0;i < n;i++){
                ti.emplace_back(cards[i][j], i);
            }
            sort(ti.begin(), ti.end());
            if(maxx > ti[0].first){
                cout << "-1\n";
                t--;
                goto outer;
            }
            for(int i = 0;i < n;i++){
                if(ti[i].second != p[i]){
                    cout << "-1\n";
                    t--;
                    goto outer;
                }
            }
            maxx = max(ti[n-1].first, maxx);
        }

        for(int i : p){
            cout << i + 1 <<' ';
        }

        cout << '\n';
    }

    return 0;
}
