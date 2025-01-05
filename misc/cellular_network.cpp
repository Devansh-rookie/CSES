#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> arr(n, 0);
    vector<long long> towers(m, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int j = 0;j < m;j++) cin >> towers[j];

    set<long long> s(towers.begin(), towers.end());

    long long ans = 0;

    for(int i = 0;i < n;i++){
        long long val = arr[i];

        long long distL = INT_MAX;
        long long distR = INT_MAX;

        auto right = s.lower_bound(val);
        // right--;
        auto left = right;
        // right++;

        if(left == s.begin()){
            distR = abs((*right) - val);
        }
        else if(right == s.end()){
            left--;
            distL = abs(val - (*left));
        }
        else{
            left--;
            distL = abs(val - (*left));
            distR = abs((*right) - val);
        }

        long long curr = min(distL, distR);
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}