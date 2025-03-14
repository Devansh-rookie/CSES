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

    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0;i < n;i++) cin >> arr[i];

    // set<pii> s;
    map<int, int> m;
    int ans = 0;
    int curr = 0;
    int mini = 0;
    int left = 0;

    for(int i = 0;i < n;i++){
        if(m.find(arr[i]) == m.end()){
            // curr++;
            m[arr[i]] = i;
            ans = max(ans,i - mini + 1);
        }
        else{
            int right = m[arr[i]];
            for(;left <= right;left++){
                m.erase(arr[left]);
            }
            m[arr[i]] = i;
            mini = left;
            // curr = i - right;
        } 

        // if(m.find(arr[i]) != m.end() && m[arr[i]] >= mini){
        //     mini = m[arr[i]] + 1;
        // }

        // m[arr[i]] = i;

        // ans = max(ans, i - mini + 1);
    }

    cout << ans;

    return 0;
}