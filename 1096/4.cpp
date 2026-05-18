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


int get_mex(int l, int r, vector<int>& a){
    if(l > r || a[l] != a[r]){
        return 0;
    }
    while(l>=0 && r<a.size() && a[l] == a[r]){
        l--;
        r++;
    }
    l++;
    r--;
    vector<bool> vis(a.size(), false);
    for(int i = l;i <= r;i++){
        vis[a[i]] = true;
    }
    int mex = 0;
    while(vis[mex]) mex++;
    return mex;
}

int main(){
    // setIO("check");
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(2*n);
        for(int i = 0 ;i<2*n;i++){
            cin >> a[i];
        }
        int zero1 = -1, zero2 = -1;
        for(int i=0 ; i<2*n ; i++){
            if(a[i] == 0 && zero1 == -1){
                zero1 = i;
            }
            else if(a[i] == 0 && zero2 == -1){
                zero2 = i;
            }
        }
        int ans = 0;
        ans = max(ans, get_mex(zero1, zero1, a));
        ans = max(ans, get_mex(zero2, zero2, a));

        int mid1 = (zero1 + zero2)/2;
        int mid2 = (zero1 + zero2 + 1)/2;
        ans = max(ans, get_mex(mid1, mid2, a));
        
        cout << ans << "\n";
    }
    return 0;
}