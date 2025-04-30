#include<bits/stdc++.h>
#include <unordered_set>
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

    vector<int> arr(n);
    for(int i = 0;i < n;){
        cin >> arr[i++];
    }

    unordered_set<int> s(arr.begin(), arr.end());
    int i;
    for(i = 1; i <= 3001;i++){
        if(s.find(i) == s.end()){
            cout << i;
            return 0;
        }
    }

    cout << i;

    return 0;
}
