#include<bits/stdc++.h>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}


void disp(vector<int> &arr){
    for(int i: arr) cout << i << " ";
    cout << endl;
}
void disp(set<int> &arr){
    for(int i: arr) cout << i << " ";
    cout << endl;
}


int main() {
    setIO("cardgame");
    int n;
    cin >> n;

    vector<int> elsie(n);

    for(int i = 0;i < n;i++) cin >> elsie[i];

    vector<int> arr;

    set<int> some(elsie.begin(), elsie.end());

    for(int i = 1;i <= 2*n;i++){
        if(some.find(i) == some.end()){
            arr.push_back(i);
        }
    }

    sort(arr.begin(), arr.end());

    // first N/2 like the smallest would be used for the end while largest for the start
    //

    set<int> start;
    set<int> last;

    for(int i = 0;i < n/2;i++){
        last.insert(arr[i]);
    }
    for(int i = n/2;i < n;i++){
        start.insert(arr[i]);
    }

    // disp(arr);
    // disp(start);
    // disp(last);

    int ans = 0;

    for(int i = 0;i < n/2;i++){
        int opp_card =elsie[i];
        auto it = start.upper_bound(opp_card);
        if(it != start.end()){
            if(opp_card < *it){
                ans++;
                start.erase(it);
            }
        }
    }
    for(int i = n/2;i < n;i++){
        int opp_card =elsie[i];
        auto it = last.upper_bound(opp_card);
        it--;
        if(it != last.end()){
            if(opp_card > *it){
                ans++;
                last.erase(it);
            }
        }
    }

    cout << ans;

    return 0;
}
