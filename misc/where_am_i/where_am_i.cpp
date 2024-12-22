#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int n;
    string s;
    fin >> n >> s;

    for(int i=0;i < n;i++){
        unordered_map<string, int> m;
        // all the substring lengths
        bool flag = true;
        for(int j = 0;j < n - i;j++){
            string s1 = s.substr(j, i+1);
            m[s1]++;
            if(m[s1] > 1){
                flag = false;
                break;
            }
        }
        if(flag){
            fout << i+1;
            return 0;
        }
    }
    return 0;
}