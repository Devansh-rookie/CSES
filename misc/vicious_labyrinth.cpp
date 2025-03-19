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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        if(k%2){
            for(int i = 0;i < n;i++){
                arr[i] = n;
            }
            arr[n-1] = n-1;
        }
        else{
            for(int i = 0;i < n;i++){
                arr[i] = n-1;
            }
            arr[n-2] = n;
        }

        for(int i : arr){
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
