#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin >> s;
    int ans = 1;
    for(int i=1; i <s.length();i++){
        int node = 1;
        while(i < s.length() && s[i] == s[i-1]){
            node++;
            i++;
        }
        ans = max(ans, node);
    }
    cout << ans<< endl;
   return 0;
}