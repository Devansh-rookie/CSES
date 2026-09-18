#include <bits/stdc++.h>
using namespace std;
#define int long long int
void ans(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i = 1;i<n+1;i++) cin>>a[i];
    vector<int>dp(n+1,0);
    for(int i = 1;i<=n;i++){
        int l = min(n,i*a[i]);
        int r = min(n,i*(a[i]+1));
        dp[l]--;
        dp[r]++;
    }
    int p = 0;
    vector<int>b;
    for(int i = 0;i<n;i++){
        p+=dp[i];
        if(p>=0){
            b.push_back(i);
        }else{

        }
    }
    cout<<b.size()<<" \n";
    for(auto x:b) cout<<x<<" ";
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        ans();
        cout<<endl;
    }
}