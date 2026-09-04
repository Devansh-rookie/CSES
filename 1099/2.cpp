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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<long long> arr(n, 0);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        if (n == 1){
            cout << "YES\n";
            continue;
        }
        long long L = 0;
        long long curr_max = arr[0];
        
        for(int i = 1; i < n; i++){
            if (curr_max > arr[i]) {
                L = max(L, curr_max - arr[i]);
            }
            curr_max = max(curr_max, arr[i]);
        }

        long long prev = arr[0];
        bool possible = true;
        
        for(int i = 1; i < n; i++){
            if(arr[i] >= prev){
                prev = arr[i];
            } 
            else if (arr[i] + L >= prev){
                prev = arr[i] + L;
            } 
            else{
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}