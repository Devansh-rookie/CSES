#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0;i < n;i++){
        cin >> arr[i];
    }

    /*
        Method 1: Kadane's Algorithm
        O(N) TC
        O(1) SC

        long long ans = LONG_MIN;
        long long curr_sum = 0;
        for(int i=0;i < n;i++){
            curr_sum += arr[i];
            ans = max(ans, curr_sum);
            if(curr_sum < 0) curr_sum = 0;
        }
        cout << ans << '\n';
    
    */

    // Method 2 using prefix sums, subtract the smallest subarray sum till now

    long long ans = arr[0];

    for(int i=1;i < n;i++){
        arr[i] += arr[i-1];
    }

    long long min_sum = 0;

    for(int i=0;i < n;i++){
        ans = max(ans, arr[i] - min_sum);// this takes the first number into account as well 
        min_sum = min(arr[i], min_sum); // smallest subaaray till now this line is below in order to prevent unneccessary 0 like minsum == arr[i] in the ans value
    } 

    cout << ans << '\n';

    return 0;
}