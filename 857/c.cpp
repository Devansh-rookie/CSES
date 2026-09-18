#include <bits/stdc++.h>
using namespace std;

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

void ans(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+5,vector<int>(m+5));
    int i = 0;
    int j = 0;
    int n1 = 0;
    while(j-1<(m+2)){
        while(i-1<(n+2)){
            a[i][j]=n1;
            n1++;
            a[i+1][j]=n1;
            n1++;
            a[i][j+1]=n1;
            n1++;
            a[i+1][j+1]=n1;
            n1++;
            i+=2;
        }
        j+=2;
        i = 0;
    }
    bool k = true;
    for(int i = 0;i<n-1;i++){
        for(int j =0;j<m-1;j++){

        }
    }
    cout<<n*m<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}
signed main(){
    setIO("check");
    int t;
    cin>>t;
    while(t--){
     ans();
    }
}
