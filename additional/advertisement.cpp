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

using pii = pair<int ,int>;

int main() {
    // setIO("check");

    int n;

    cin >> n;

    vector<int> heights(n, 0);

    for(int i = 0;i < n;i++) cin >> heights[i];
    
    stack<pii> mono_stack;
    long long ans = 0;
    for(int i = 0;i < n;i++){
        int current = i; // this is for pointing the back index

        // go to the smallest one while calcing the ans
        while(!mono_stack.empty() && heights[i] < mono_stack.top().second){
            pii tarnished = mono_stack.top();
            current = tarnished.first;
            ans = max(ans, 1LL*tarnished.second * (i - current));
            mono_stack.pop();
        }

        mono_stack.push({current, heights[i]});
    }
    
    // monotonically increasing it means start from the end

    while(!mono_stack.empty()){
        pii tarnished = mono_stack.top();
        ans = max(ans, 1LL*tarnished.second * (n - tarnished.first));
        mono_stack.pop();
    }
    
    cout << ans << endl;

    return 0;
}