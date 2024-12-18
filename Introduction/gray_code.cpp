#include<bits/stdc++.h>
using namespace std;

void decToBinary(int n, int maxx)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = maxx; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // og num then n>>1 and take XOR for n
    // 100110
    // 010011

    // 110101

    int n;
    cin >> n;
    long long maxx = pow(2, n);
    for(int i=0;i < maxx;i++){
        long long newnum = (i)^(i>>1);
        decToBinary(newnum, n-1);
        cout << endl;
    }
    return 0;
}