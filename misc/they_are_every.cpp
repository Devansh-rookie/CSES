#include<bits/stdc++.h>
using namespace std;
bool check(map<char, int> &m1, map<char, int> &m2){
    for(auto const&[val, freq] : m1){
        if(!m2[val]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;

    map<char, int> m1;
    map<char, int> m2;

    for(char c : s) m1[c]++;

    int left = 0;
    int right = 0;

    int dst = m1.size();

    int ans = INT_MAX;
    
    // while(right < n){
    //     while(right < n && !check(m1, m2)){
    //         m2[s[right]]++;
    //         right++;
    //     }
    //     ans = min(ans, right - left);
    //     m2[s[left]]--;
    //     if(!m2[s[left]]){
    //         m2.erase(s[left]);
    //     }
    //     if(left < right) left++;
    //     // left++;
    // }

    while(right < n){
        m2[s[right]]++;
        right++;

        // here we had to think that we increase the value of right like expand the window everytime but contract when we need it only like when we satisfy the coondition then we check if we can do it.

        while(m2.size() == dst){
            ans = min(ans, right - left);
            m2[s[left]]--;
            if(!m2[s[left]]) m2.erase(s[left]);
            left++;
        }
    }

    cout << ans << endl;
    return 0;
}