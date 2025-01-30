#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) x.begin(), x.end()
using ll = long long;


void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool num_subarray_valid(vi &arr, ll max_suma, const int &k){
    // the subarrays should all be less than or equal to the max_suma

    int num_subarray = 0;
    ll rolling_sum = 0;

    for(int &i: arr){
        if(i > max_suma) return false;
        if(rolling_sum + i > max_suma){
            num_subarray++;
            rolling_sum = 0;
        }

        rolling_sum += i;
    }

    if(rolling_sum) num_subarray++;

    return num_subarray <= k;
}

int main() {
    // setIO("check");

    int n, k;
    cin >> n >> k;
    vi arr = vi(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];

    ll suma = 0;

    for(int &i : arr){
        suma += i;
    }

    ll lo, hi, mid;
    // even 0 would work
    lo =0; // max element would be the least suma
    hi = suma; // start from here

    while(lo < hi){
        // as mid and mid - 1 so can't keep lo <= hi as it would be infinite loop

        mid = lo + (hi - lo)/2;

        if(num_subarray_valid(arr, mid, k)){
            // this means that we were able to split so decrease it now
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    // hi would be equal to lo in the end and lo = mid + 1 in the for more refer to iPad notes practice DSA in sem 4
    cout << lo;

    return 0;
}