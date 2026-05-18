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

int main(){
    // setIO("check");
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    long long ans = 0;
    for(int i = n-1;i >= n/2;i--){
        ans += a[i];
    }
    cout << ans << "\n";
    return 0;
}