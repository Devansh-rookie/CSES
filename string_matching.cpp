#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string p;

    cin >> s;
    cin >> p;
    int n=0, m=0;
    int ans = 0;
    for(int i=0;i < n;i++){
        int j = i;
        while(j < m && i+j < n && s[i+j] == p[j]){
            j++;
        }
        if(j == m){
            i = j;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}