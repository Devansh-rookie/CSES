#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    // setIO("check");
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> a(n+2);
        for(int i = 1;i<=n;i++){
            cin>>a[i];
        }
        vector<ll> s(n+2);
        s[n+1] = 2e9;
        for(int i = n;i>=1;i--) {
            s[i] = min(a[i], s[i + 1]);
        }

        ll total = 0;
        ll blocked = 0;
        for (int i = 1; i <= n; i++) {
            total += a[i];
            blocked += s[i];
        }
        ll base = total - blocked;

        vector<int> close_left(n+1, 0);
        stack<int> st;
        for(int i = 1;i<=n;i++){
            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            if (!st.empty()){
                close_left[i] = st.top();
            }
            else{
                close_left[i] = 0;
            }
            st.push(i);
        }

        ll max_gain = 0;
        for(int k = 1;k<=n;k++){
            if(a[k] <= s[k+1]){
                ll gain = (k - close_left[k]) - 1;
                max_gain = max(max_gain, gain);
            }
        }

        cout<<base + max_gain<<"\n";
    }
    return 0;
}