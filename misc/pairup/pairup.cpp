#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    long long n;
    fin >> n;
    map<long long , long long> m;
    for(int i = 0;i < n;i++){
        long long freq, out;
        m[out] += freq;
    }

    map<long long, long long>::iterator left = m.begin();
    map<long long, long long>::iterator right = m.end();

    right--;

    long long ans = 0;

    while(right->first >= left->first){
        
    }
    return 0;
}