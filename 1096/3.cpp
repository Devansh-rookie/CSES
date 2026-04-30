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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> t6, t2, t3, t1;
        for (int i = 0; i < n; i++){
            int x;
            cin>> x;
            if (x%6== 0){
                t6.push_back(x);
            } else if (x%2 == 0){
                t2.push_back(x);
            } else if (x%3 == 0){
                t3.push_back(x);
            } else {
                t1.push_back(x);
            }
        }
        
        for(int x:t6) cout<< x << " ";
        for(int x:t2) cout<< x << " ";
        for(int x:t1) cout<< x << " ";
        for(int x:t3) cout<< x << " ";
        
        cout<<"\n";
    }
    return 0;
}