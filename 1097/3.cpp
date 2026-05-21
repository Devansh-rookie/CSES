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
bool reg(string& seq) {
    int b = 0;
    for (char c : seq) {
        if (c == '(') {
            b++;
        } else {
            b--;
        }
        if (b < 0) {
            return false;
        }
    }
    return b == 0;
}
int main(){
    // setIO("check");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int turn = 0;
        for(int i = 0;i < n;i++){
            if(a[i]!=b[i]){
                if(!turn){
                    a[i] = '(';
                    b[i] = ')';
                }
                else{
                    a[i] = ')';
                    b[i] = '(';
                }
                turn = 1-turn;
            }
        }
        if(reg(a)&&reg(b)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}