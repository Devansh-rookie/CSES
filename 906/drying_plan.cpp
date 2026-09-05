#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e6;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct event{
    int time;
    bool type; // 0 start(l), 1 end(r)
    int id;
};

bool cmp(const event &a, const event &b){
    if(a.time != b.time)
        return a.time < b.time;
    return a.type < b.type;
}

ll key(int i, int j){
    return 1LL* i * MAXN + j;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vpii rains(m);
    vector<event> events;
    for(int i = 0;i < m;i++){
        cin >> rains[i].first >> rains[i].second;
        event e1 ({rains[i].first, 0, i});
        event e2 ({rains[i].second + 1, 1, i});
        events.push_back(e1);
        events.push_back(e2);
    }
    sort(all(events), cmp);
    // find cities > 2 and remove them
    map<ll, int> freq;
    set<int> active;
    int dry = 0;
    int prev = 1;
    int p = 0;
    // maximize this: score = freq[key(x, 0)] + freq[key(y, 0)] + freq[key(x, y)], each city should have the sets of days in which rains
    while(p < events.size()){
        int curr = events[p].time;
        int len = curr - prev;
        if(active.empty()) dry += len;
        else if(active.size() == 1) freq[key(*active.begin(), 0)] += len;
        else if(active.size() == 2){
            auto it = active.begin();
            int x = *it;
            ++it;
            int y = *it;
            freq[key(x, y)] += len;
        }
        while(p < events.size() && events[p].time == curr){
            int id = events[p].id;
            if(events[p].type == 0) active.insert(id);
            else active.erase(id);
            p++;
        }
        prev = curr;
    }
    if (prev <= n && active.empty()) {
        dry += n - prev + 1;
    }
    int best1 = 0, best2 = 0;
    for(auto &[k, val]: freq){
        int x = k/ MAXN;
        int y = k % MAXN;
        if(y!= 0) continue;
        if(val >= best1){
            best2 = best1;
            best1 = val;
        }
        else if(val > best2){
            best2 = val;
        }
    }

    int ans = best1 + best2;

    for(auto &[k, both]: freq){
        int x = k/ MAXN;
        int y = k % MAXN;
        if(y == 0) continue;
        int x0 = freq[key(x, 0)];
        int y0 = freq[key(y, 0)];
        int score = x0 + y0 + both;
        ans = max(ans, score);
    }
    cout << dry + ans << '\n';
}

int main() {
    // setIO("check");
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
