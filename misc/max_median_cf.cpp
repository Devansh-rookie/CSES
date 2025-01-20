#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, k;
vector<ll> arr;

bool function_check(ll new_med){
    ll operation = 0;
    for(int i = (n)/2 ;i < n;i++){ // difference with all whatever needs changing add it to the operation
        if(arr[i] < new_med) operation += (new_med - arr[i]);
        if(k < operation) return false; // here the thing already failed
    }

    return k >= operation;
}

int main() {
    // setIO("check/check");
    cin >> n >> k;

    arr.resize(n, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];

    // binary search on all medians and find the last true value as its basically a monotonically non increasing function
    // find the most value at which its satisfied

    // last_true function basically; 11110000 that type of a function
    sort(arr.begin(), arr.end());
    ll lo, hi;
    lo = 0;
    hi = INT32_MAX;
    ll mid = 0;
    while(lo < hi){
        mid = lo + (hi - lo + 1)/2; // this mid is the new median to check on
        if(function_check(mid)){
            lo = mid; // this could also be the answer thats why no +-1
        }
        else hi = mid - 1; // answer could be just before check the graph that makes it super clear
    }
    // lo is the answer in the end as mid - 1 must be smaller than lo and that was the number which satisied the function in the end
    cout << lo;

    return 0;
}