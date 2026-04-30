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

set<int> getNum(int n){
    set<int> s;

    while(n){
        s.insert(n%10);
        n = n/10;
    }
    return s;
}

int main() {
    // setIO("check");

    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;

        cout << *getNum(x).begin() << endl;
    }

    return 0;
}
