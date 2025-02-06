#include<bits/stdc++.h>
#include <set>
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

    multiset<int> m;

    for(int i = 0;i < n;i++){
        int val;
        cin >> val;

        if(m.upper_bound(val) == m.end()){
            m.insert(val);
        }
        else{
            m.erase(m.upper_bound(val));
            m.insert(val);
        }
    }

    cout << m.size();

    return 0;
}
