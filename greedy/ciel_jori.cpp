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

int main(){
    // setIO("check");
    int n, m;
    cin >> n >> m;
    vector<multiset<int>> jori(2);
    multiset<int> ciel;
    
    for(int i = 0;i < n;i++){
        string s;
        int num;
        cin >> s >> num;
        if(s == "ATK") jori[0].insert(num);
        else jori[1].insert(num);
    }
    for(int i = 0;i < m;i++){
        int num;
        cin >>num;
        ciel.insert(num);
    }

    int s1 = 0, s2 = 0;
    auto it = ciel.rbegin();auto itjori = jori[0].begin();
    // S1
    for(; it != ciel.rend() && itjori != jori[0].end(); ++it, ++itjori){     
        int value = *it - *itjori;
        if(value >= 0) s1 += value;
        else break;
    }

    // S2

    bool can_clear = true;
    multiset<int> ciel_s2 = ciel; 
    for(int def_val : jori[1]){
        auto just_larger = ciel_s2.upper_bound(def_val); 
        if(just_larger == ciel_s2.end()){
            can_clear = false; 
            break; 
        }
        ciel_s2.erase(just_larger); 
    }

    if(can_clear){
        for(int atk_val : jori[0]){
            auto just_sufficient = ciel_s2.lower_bound(atk_val); 
            if(just_sufficient == ciel_s2.end()){
                can_clear = false;
                break;
            }
            s2 += (*just_sufficient - atk_val); 
            ciel_s2.erase(just_sufficient); 
        }
    }
    if(can_clear){
        for(int remaining_card : ciel_s2){
            s2 += remaining_card;
        }
    } else {
        s2 = 0;
    }

    cout << max(s1, s2) << endl;
    return 0; 
}