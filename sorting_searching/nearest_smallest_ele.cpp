#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
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
    int n;
    cin >> n;

    stack<pii> stk;
    stk.push(make_pair(0,0));

    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        // monotonic stack for lookup time O(1)
        while(!stk.empty() && stk.top().second >= x) stk.pop();
        // can't be empty as {0, 0} is at the start and look at it graphically like mountains when water comes down it gets stuck on the ridge the lower it goes the lower it is for all but it doesn't matter since we are pusching to the mountains continuosly as well so if there is something when is starts inscreasing we have the new minimum until we go below it.

        cout << stk.top().first << ' ';
        stk.push(make_pair(i, x));
    }

    return 0;
}
