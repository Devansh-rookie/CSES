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

int main(){
    // setIO("check");
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        if(x%2 == 0 && y%2 == 0){
            cout<<"Yes\n";
        }
        else if(x%2 == 1 && y%2 == 0){
            cout<<"Yes\n";
        }
        else if(x%2 == 0 && y%2 == 1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}
