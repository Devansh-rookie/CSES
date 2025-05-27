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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2 == 0){
            cout << n*n / 4 + 1<< endl;
        }
        else{
            cout << (n*n - 1) / 4 + 1 << endl;
        }
    }

    return 0;
}
