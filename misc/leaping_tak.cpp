#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main(){
    int n, k;
    cin >> n >> k;
    vector<pii> ranges(k);
    // set<int> s;
    for(int i = 0;i < k;i++){
        int l, r;
        cin >> l >> r;
        ranges[i].first = l;
        ranges[i].second = r;
    }
    
    
    return 0;
}