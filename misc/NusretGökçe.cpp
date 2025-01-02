#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;

    cin >> n >> m;
    vector<long long> arr(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];

    // got from left to right and then from right to left to confirm that you get the right shit

    for(int i = 0;i < n-1;i++){
        // check right and left what is happening, like change the smaller value if it doesn't satisfy
        if(arr[i+1] > arr[i] + m){
            arr[i] = arr[i+1] - m;
        }
        else if(arr[i] > arr[i+1] + m){
            arr[i+1] = arr[i] - m;
        }
    }

    for(int i = n-2;i >= 0;i--){
        // check right and left what is happening, like change the smaller value if it doesn't satisfy
        if(arr[i+1] > arr[i] + m){
            arr[i] = arr[i+1] - m;
        }
        else if(arr[i] > arr[i+1] + m){
            arr[i+1] = arr[i] - m;
        }
    }

    for(int i: arr){
        cout << i << ' ';
    }
    return 0;
}