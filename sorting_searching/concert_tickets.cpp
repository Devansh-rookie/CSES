#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> temp(n, 0);
    for(int i = 0;i < n;i++){
        cin >> temp[i];
    }
    map<long long, long long> s;

    for(int i = 0;i < n;i++){
        s[temp[i]]++;
    }

    vector<long long> arr(m, 0);
    for(int i = 0;i < m;i++){
        cin >> arr[i];
    }

    for(int i = 0;i < m;i++){
        int val = arr[i];
        if(s.empty()){cout <<"-1\n"; continue;}
        auto maxx = s.upper_bound(val);

        if(maxx == s.begin()){
            cout << "-1\n";
        }
        else{
            maxx--;
            cout << (maxx->first) << '\n';
            s[maxx->first]--;
            if(!s[maxx->first]) s.erase(maxx);
        }
    }
    return 0;
}