#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i < n;i++) cin >> arr[i];

        // sort(arr.begin(), arr.end());

        // if(arr[0] == arr[n-1]){
        //     cout << "YES\n";
        //     continue;
        // }

        // if(arr[0]*2<= arr[1]){
        //     cout << "NO\n";
        // }
        // else cout << "YES\n";
        bool possible = false;
        for(int i=0;i < n-1;i++){
            if((arr[i] + arr[i+1] > arr[i]) && (arr[i]*2 > arr[i+1])&&(arr[i+1] *2 > arr[i]) && (arr[i]+arr[i+1] > arr[i+1])){
                possible = true;
                break;
            }
        }
        if(possible) cout << "YES\n";
        else cout <<"NO\n";
    }
    return 0;
}