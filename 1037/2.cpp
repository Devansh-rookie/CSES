#include<bits/stdc++.h>
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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for(int i = 0;i < n;i++) cin >> arr[i];
        vector<int> zeroes;
        int toadd = 0;
        for(int i = 0;i < n;i++){
            if(arr[i] == 0){
                toadd++;
            }
            else{
                zeroes.push_back(toadd);
                toadd = 0;
            }
        }

        if (toadd > 0) zeroes.push_back(toadd);

        int ans = 0;

        for(int vals: zeroes){
            int valid = (vals+1)/(k+1);
            // if(valid%(k+1) == k){
            //     ans += 1;
            // }
            ans += valid;
        }

        cout << ans << endl;
    }

    return 0;
}
