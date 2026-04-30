#include<bits/stdc++.h>
#include <string>
#include <vector>
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

// bool func(ll burgers, vector<int>& count, vector<int>& ns, vector<int>& ps, ll r){
//     ll curr = 0;
//     curr += min({ns[0]/count[0], ns[1]/count[1], ns[2]/count[2]});

//     for(int i = 0; i < 3; i++){
//         ns[i] -= count[i] * curr;
//     }

//     vector<ll>req(3, 0);
//     for(int i = 0;i < 3;i++){
//         req[i] = (burgers - curr) / count[i];
//     }

//     for(int i = 0;i < 3;i++){
//         req[i] -= ns[i];
//     }

//     ll required_rubles = 0;
//     for(int i = 0;i < 3;i++){
//         if (req[i] >= 0) required_rubles += req[i] * ps[i];
//     }

//     if(required_rubles <= r) return true;
//     return false;
// }


bool func(ll burgers, vector<int>& count, vector<int>& ns, vector<int>& ps, ll r){
    vector<ll> req(3, 0); // required ingredients to buy

    for(int i = 0; i < 3; i++){
        req[i] = max(0LL, burgers * 1LL * count[i] - ns[i]); // compute how much more we need
    }

    ll required_rubles = 0;
    for(int i = 0; i < 3; i++){
        required_rubles += req[i] * ps[i];
    }

    if(required_rubles <= r) return true;
    return false;
}


int main() {
    // setIO("check");

    string s;
    cin >> s;

    vector<int> count(3, 0);

    for(char c: s){
        if(c == 'B'){
            count[0]++;
        }
        else if(c == 'S'){
            count[1]++;
        }
        else if(c == 'C'){
            count[2]++;
        }
    }

    vector<int> ns(3, 0);
    vector<int> ps(3, 0);

    for(int i = 0; i < 3; i++){
        cin >> ns[i];
    }

    for(int i = 0; i < 3; i++){
        cin >> ps[i];
    }

    ll r;

    cin >> r;

    ll ans = 0;
    ll low = 0;
    ll high = 1e13 + 1;

    while(low <= high){
        ll mid = low + (high - low)/2;
        if(func(mid, count, ns, ps, r)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
