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
        vector<int> arr(4, 0);

        for(int i = 0;i < 4;i++) cin >> arr[i];

        int val1 = arr[0] + arr[1];
        int val2 = arr[3] - arr[2];
        int val3 = arr[2] - arr[1];

        int ans = 1;

        if(val1 == val3 && val1 == val2){
            ans = 3;
        }

        else if(val1 == val2 || val2 == val3 || val1 == val3){
            ans = 2;
        }

        cout << ans<< '\n';
    }

    return 0;
}