#include <bits/stdc++.h>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int n = (int)A.size();
    if (n == 0) return 0;             // defensive, though N ≥ 1 by statement
    vector<int> pref(n), suff(n);

    // prefix maxima
    int mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, A[i]);
        pref[i] = mx;
    }

    // suffix minima
    int mn = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        mn = min(mn, A[i]);
        suff[i] = mn;
    }

    // count valid split points; distinct elements ⇒ strict '<'
    int slices = 1; // at least one slice
    for (int i = 0; i + 1 < n; ++i) {
        if (pref[i] < suff[i + 1]) ++slices;
    }
    return slices;
}

#include <bits/stdc++.h>
using namespace std;

// Codility-style signature
int solution2(vector<int> &A) {
    int n = (int)A.size();
    if (n == 0) return 0; // just in case

    int best = 1; // at least one element alone has AND > 0
    for (int b = 0; b < 31; ++b) {  // numbers up to 1e9 need 30 bits; 31 is safe
        int cnt = 0;
        int mask = 1 << b;
        for (int x : A) if (x & mask) ++cnt;
        best = max(best, cnt);
    }
    return best;
}


vector<int> solution3(vector<int> &skills) {
    int n = (int)skills.size();
    vector<int> res(n, 0);

    // current participants as original indices
    vector<int> cur(n);
    iota(cur.begin(), cur.end(), 0);

    int round = 1;
    while (cur.size() > 1) {
        vector<int> next;
        next.reserve(cur.size() / 2);

        for (size_t i = 0; i < cur.size(); i += 2) {
            int a = cur[i], b = cur[i + 1];
            if (skills[a] > skills[b]) {
                res[b] = round;      // loser eliminated this round
                next.push_back(a);   // winner advances
            } else {
                res[a] = round;
                next.push_back(b);
            }
        }
        cur.swap(next);
        ++round;
    }

    // The last remaining player participated up to the final round
    res[cur] = round - 1;
    return res;
}


void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("check");

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    // cout << solution3(arr);

    vector<int> ans = solution3(arr);

    for(int i: arr){
        cout << i << ' ';
    }

    return 0;
}
