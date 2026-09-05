#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e6;

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
    vi arr(MAXN + 1, 0); // or make an array with normal values then initialize an array with the max only

    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        arr[x]++;
    }

    // potential gcd
    for(int gcd = MAXN;gcd >= 2;gcd--){
        int num_divs = 0;
        for(int i = gcd;i <= MAXN;i+=gcd){
            num_divs += arr[i];
        }
        if(num_divs >= 2) {cout << gcd << '\n'; return 0;}
    }
    cout << 1 << '\n';
    return 0;
}
