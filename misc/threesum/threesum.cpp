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

using ll = long long;
using pll = pair<ll, ll>;
int main() {
    setIO("threesum");

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n, 0);
    map<ll, vector<pll>> m;


    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            m[arr[i] + arr[j]].emplace_back(i, j);
        }
    }

    for(int qq = 0;qq < q;qq++){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for(int i = a;i <= b;i++){
            if(m.find(-arr[i]) != m.end()){
                for(auto &val: m[-arr[i]]){
                    int f = val.first;
                    int s = val.second;

                    if(f != i && s != i){
                        ans++;
                    }
                }
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}