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

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


int main() {
    // setIO("check");

    int a,b, c , d;
    cin >> a >> b >> c >> d;

    if(a*d > b*c){
        int num = a*d - b*c;
        int deno = a*d;
        int val = gcd(num, deno);
        num /= val;
        deno /= val;
        cout << num << "/" << deno << endl;
    }
    else if(a*d == b*c){
        cout << "0/1" << endl;
    }
    else{
        int num = b*c - a*d;
        int deno = b*c;
        int val = gcd(num, deno);
        num /= val;
        deno /= val;
        cout << num << "/" << deno << endl;
    }

    return 0;
}
