#include<bits/stdc++.h>
#include <system_error>
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

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i];
    int likes = 0;
    int dislikes = 0;
    for(int i : arr){
        if(i > 0) likes++;
        else dislikes++;
    }
    int temp = likes;
    for(int i = 1;i <= n;i++){
        if(i <= likes) cout << i << ' ';
        else cout << --temp << ' ';
    }
    cout << '\n';
    for(int i = 1;i <= n;i++){
        if(i <= 2*dislikes) cout << i%2 << ' ';
        else cout << i - 2*dislikes << ' ';
    }
    cout << '\n';
}

int main() {
    // setIO("check");

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
