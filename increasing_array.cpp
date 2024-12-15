#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i < n;i++){
        cin >> arr[i];
    }

    int val = arr[0];
    long long ans = 0;
    for(int i=1;i < n;i++){
        if(arr[i] < val){
            ans += val - arr[i];
            arr[i] = val;
        }
        else val = arr[i];
    }
    cout << ans << endl;
   return 0;
}