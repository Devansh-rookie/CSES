#include <algorithm>
#include<bits/stdc++.h>
#include <functional>
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
    vector<int> bi(n);
    vector<int> gj(m);
    for(int i = 0;i < n;i++) cin >> bi[i];
    for(int j = 0;j < m;j++) cin >> gj[j];

    // I dont think that there is need of an extra array for other stuff like checking is minimal has been reached



    long long ans = 0;

    sort(gj.begin(), gj.end());
    sort(bi.begin(), bi.end());
    // sum excluding the max which would only be included in the end
    if(gj[0] < bi[n-1]){
        cout << -1;
        return 0;
    }
    long long suma = 0;

    for(int i = 0;i < n;i++){
        suma += bi[i];
    }
    ans += suma*m; // baseline

    for(int i = 1;i < m;i++){
        ans += gj[i] - bi[n-1];
    }
    // in c++ 20 bi[n-2] is 0 by default I think atleast
    if(gj[0] != bi[n-1]) ans += gj[0]-bi[n-2]; // if its equal then use the max there no issues which would be 0 again
    // else use the minimal value of the max
    cout << ans;

    return 0;
}
