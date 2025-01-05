#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    multiset<int> m;
    m.insert(x);

    set<int> s;
    s.insert(0);
    s.insert(x);

    for(int i = 0;i < n;i++){
        int pos;
        cin >> pos;

        auto left = s.upper_bound(pos);
        auto right = left;
        left--;

        m.erase(m.find((*right) - (*left)));
        m.insert((*right) - pos);
        m.insert(pos - (*left));
        s.insert(pos);
        cout << *(--m.end()) << ' ';
    }

    return 0;
}