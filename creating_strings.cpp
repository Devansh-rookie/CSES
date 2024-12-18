#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&ch, string ansnode, unordered_set<string> &check, int n){
    int len = ansnode.length();
    if(len == n && check.find(ansnode) == check.end()){
        for(char c: ansnode){
            cout << c;
        }
        cout << endl;
        check.insert(ansnode);
        ansnode.clear();
        return;
    }

    for(int i=0;i < 26;i++){
        if(ch[i]){
            // ch[i]--;
            ansnode += ((char)i + 'a');
            ch[i]--;
            solve(ch, ansnode, check, n);
            // ch[i]++;
            ansnode.pop_back();
            ch[i]++;
        }
    }
}

long fac(int n, vector<int> &dp){
    if(n<=1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = n*fac(n-1, dp);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;
    int n = s.length();
    vector<int> ch(26, 0);
    unordered_set<string> check;
    for(char c: s){
        ch[c - 'a']++;
    }
    vector<int> dp(n+1, -1);
    int ans = fac(n, dp);
    for(int i=0;i < 26;i++){
        if(ch[i]){
            ans /= fac(ch[i], dp);
        }
    }
    cout << ans << endl;
    solve(ch, "", check, n);

    return 0;
}