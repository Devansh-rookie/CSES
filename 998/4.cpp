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

string solve(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];

    if(arr[0] > arr[1]) return "NO";

    for(int i = 1;i < n - 1;i++){
        // if(arr[i] > arr[i+1]){
        //     int val = min(arr[i], arr[i-1]);
        //     arr[i] = arr[i] - val;
        //     arr[i-1] = arr[i-1] - val;
        //     if(arr[i+1] < arr[i]) return "NO";
        //     if(i >= 2 && arr[i - 1] < arr[i-2]){
        //         return "NO";
        //     }
        // }
        int val = min(arr[i], arr[i-1]);
        arr[i] = arr[i] - val;
        arr[i-1] = arr[i-1] - val;
    }

    for(int i = 0;i < n-1;i++){
        if(arr[i] > arr[i+1]) return "NO";
    }

    return "YES";
}

int main() {
    // setIO("check");

    int t;
    
    cin >> t;

    while(t--){
        cout << solve() << endl;
    }

    return 0;
}