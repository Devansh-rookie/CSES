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
using ll = long long;
void solve(int n){
    vector<ll> b(2*n, 0);

    for(int i = 0;i < 2*n;i++) cin >> b[i];

    sort(b.begin(), b.end());

    ll some = b.back();
    b.pop_back();

    ll x = some; // x would be the a1 and it would be made such that when some is reduced by all the distances it is x

    for(int i = 1;i < b.size() - 1;i+=2){
        some += abs(b[i] - b[i+1]);
    }
    // to make all pair use i = 1 else we would have used i = 0 if it was all even

    some += b[0];

    cout << x << ' ' << some << ' ';
    for(ll &i : b) cout << i << ' ';
    cout << endl;
}


int main() {
    // setIO("check");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}