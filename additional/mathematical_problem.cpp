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

void solve(int n, string s)
{
    int best_ans = 10000000;
    for(int k = 0; k < n - 1; k++)
    {
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            string cur = "";
            if(i == k)
            {
                cur+=s[i];
                cur+=s[i+1];
                i++;
            }
            else
            {
                cur += s[i];
            }
            v.push_back(stoi(cur));
        }
        for(int x : v)
        {
            if(x == 0)
            {
                cout<<0<<"\n";
                return;
            }
        }
        int cur_ans = 0;
        int cur_val = v[0];
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i] * cur_val < v[i] + cur_val)
            {
                cur_val *= v[i];
            }
            else
            {
                cur_ans += cur_val;
                cur_val = v[i];
            }
        }
        cur_ans += cur_val;
        best_ans = min(best_ans, cur_ans);
    }
    cout<<best_ans<<"\n";
}


int main() {
    // setIO("check");

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(n, s);
    }

    return 0;
}
