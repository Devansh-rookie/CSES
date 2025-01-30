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

int main() {
    // setIO("check");

    int n;
    cin >> n;
    cout << (n - (n/2) + 1)*(n/2);

    return 0;
}