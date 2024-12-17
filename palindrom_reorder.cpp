#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    int n = s.length();
    vector<int> c(26, 0);
    for(char ch: s){
        c[ch-'A']++;
    }

    if(n%2 == 1){
        int numb_odd = 0;
        for(int i=0; i < 26 && numb_odd < 2;i++){
            if(c[i]%2 == 1) numb_odd++;
        }
        if(numb_odd != 1){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        int odd = 0;
        for(int i=0;i < 26;i++){
            if(c[i]%2 == 1) odd = i;
            for(int j = 0;j < c[i]/2;j++){
                cout << (char)(i+'A');
            }
        }
        cout << (char)(odd+'A');
        for(int i=25;i >=0;i--){
            for(int j = 0;j < c[i]/2;j++){
                cout << (char)(i+'A');
            }
        }
    }
    else{
        int numb_odd = 0;
        for(int i=0; i < 26 && numb_odd < 2;i++){
            if(c[i]%2 == 1) numb_odd++;
        }
        if(numb_odd){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        for(int i=0;i < 26;i++){
            for(int j = 0;j < c[i]/2;j++){
                cout << (char)(i+'A');
            }
        }
        for(int i=25;i >=0;i--){
            for(int j = 0;j < c[i]/2;j++){
                cout << (char)(i+'A');
            }
        }
    }

    return 0;
}