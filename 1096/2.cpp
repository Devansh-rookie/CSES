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
        int n;
        cin >> n;
        string s;
        cin>>s;
        int open = 0;
        int close = 0;
        for(int i =0 ;i < n;i++){
            if(s[i] == '('){
                open++;
            }
            else{
                close++;
            }
        }
        if(open != close){
            cout<<"No\n";
        }
        else{
            cout << "Yes\n";
        }
    }
    return 0;
}
