#include<bits/stdc++.h>
#include <cstdlib>
#include <cwchar>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int MOD = 1e9 + 7;

int powmod(int a, int b, int MOD){
    if(!b) return 1;
    int half_power = powmod(a, b/2, MOD);
    if(!(b % 2)) return ((1LL * half_power * half_power)%MOD)%MOD; // or use (long long), else there would be interger overflow
    return (((1LL * half_power * half_power)%MOD)* 1LL * a)%MOD;
}


int main() {
    // setIO("check");
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >>c;

        int btoc_M_1 = powmod(b, c, MOD - 1);
        int atosomething_M = powmod(a, btoc_M_1, MOD);
        cout << atosomething_M << endl;
    }

    return 0;
}
