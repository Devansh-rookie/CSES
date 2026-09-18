#include<bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvl = vector<vll>;
#define all(x) x.begin(), x.end()

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct Event{
    int time;
    bool type;// 0 start 1 end
};

bool comp(const Event& a, const Event& b){
    if(a.time == b.time){
        return a.type < b.type;
    }
    return a.time < b.time;
}

int main() {
    setIO("");
    int n;
    cin >> n;
    vector<Event> a;
    for(int i = 0;i < n;i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, 0});
        a.push_back({y, 1});
    }
    sort(all(a), comp);
    int current_screens_active = 0;
    for(Event e: a){
        // cout << e.time << ',' << e.type << ' ';
        if(!e.type) current_screens_active++;
        else current_screens_active--;
        if(current_screens_active == 3){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
