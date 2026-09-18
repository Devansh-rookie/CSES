#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("");

    int n, c;
    cin >> n >> c;

    vi a(n);
    int max_elem = 0;
    int total_c = 0;
    for(int i = 0;i < n;i++){ cin >> a[i]; max_elem = max(max_elem, a[i]); if(a[i] == c)total_c++;}

    vi best(max_elem + 1, 0);
    int freq_c = 0;
    int ans = total_c;
    for(int i = 0;i < n;i++){
        int x = a[i];
        if(x == c){freq_c++;continue;}
        // else{
        //     best[x] = max(best[x] - freq_c, 0) + 1;
        // }
        best[x] = max(freq_c, best[x]) + 1;
        ans = max(ans, best[x] + total_c - freq_c);
    }

    cout << ans << '\n';

    return 0;
}
