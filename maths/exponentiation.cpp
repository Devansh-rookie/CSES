#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int powmod(int a, int b){
    if(!b) return 1;
    int half_power = powmod(a, b/2);
    if(!(b % 2)) return ((1LL * half_power * half_power)%MOD)%MOD; // or use (long long), else there would be interger overflow
    return (((1LL * half_power * half_power)%MOD)* 1LL * a)%MOD;
}

int main() {
    // setIO("check");

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        cout << powmod(a, b) << endl;
    }

    return 0;
}
