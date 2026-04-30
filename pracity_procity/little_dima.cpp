#include<bits/stdc++.h>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int digits_sum(int val){
    int ans = 0;
    while(val != 0){
        ans += val%10;
        val/=10;
    }
    return ans;
}

int main() {
    // setIO("check");

    int a, b, c;
    cin >> a >> b >> c;
    vector<long long> ans;
    for(int i = 1;i <= 81;i++){
        long long val = b*pow(i, a) + c;
        if(val >= 1e9) continue;
        if(digits_sum(val) == i){
            ans.push_back(val);
        }
    }

    cout << ans.size() << endl;

    for(auto i: ans){
        cout << i << ' ';
    }

    return 0;
}
