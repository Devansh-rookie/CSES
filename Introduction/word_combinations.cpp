#include<bits/stdc++.h>
using namespace std;

int solve(string &str, vector<string>& arr, int index, string ans, unordered_map<string, int>&dp){
    int n = arr.size();
    if(ans.length() > str.length()) return 0;
    if(ans == str) return 1;
    if(index == n) return 0;
    if(dp.find(ans) != dp.end())return dp[ans];
    int node = 0;
    for(int i= index;i < n;i++){
        node += solve(str, arr, i, ans + arr[i], dp);
    }
    return dp[ans] = node;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;

    int k;
    cin >> k;
    vector<string> arr;
    for(int i=0;i < k; i++){
        string val;
        cin >> val;
        arr.push_back(val);
    }

    // check in how many ways the string can be made using a dp table with unordered_map, string as key

    unordered_map<string, int> dp;


    cout << solve(str, arr, 0, "", dp) <<endl;
    return 0;
}