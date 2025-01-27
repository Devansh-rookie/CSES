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

void generatePrime(int n)
{
    int X = 0, i = 2;
    bool flag;
    while(X < n){
        flag = true;
        for(int j = 2; j <= sqrt(i); j++){
            if (i%j == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << endl;
            X++;
        }
        i++;
    }
    // cout << endl;
}

int main() {
    setIO("gene");

    int n = 10000;

    cout << n << endl;

    generatePrime(n);

    return 0;
}