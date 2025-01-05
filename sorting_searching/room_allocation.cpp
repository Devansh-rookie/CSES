#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> rooms(n, 0);
    vector<pii> times(n);
    for(int i = 0;i < n;i++){
        cin >> times[i].first;
        cin >> times[i].second;
    }
    sort(times.begin(), times.end());

    multiset<int> m;

    for(int i = 0;i < n;i++){
        
    }
    return 0;
}