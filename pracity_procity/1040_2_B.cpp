#include<bits/stdc++.h>
#include <numeric>
using namespace std;

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
        int n, s;
        cin >> n >> s;
        vector<int> arr(n);
        for(int i = 0;i < n;i++) cin >> arr[i];

        int simple_sum = 0;
        simple_sum = accumulate(arr.begin(), arr.end(), 0);

        if(simple_sum > s){
            for(int i: arr){
                cout << i << ' ';
            }
            cout << endl;
            continue;
        }
        if(simple_sum + 1 == s){
            vector<int> c(3, 0);
            for(int i : arr){
                c[i]++;
            }

            for(int i = 0;i < c[0];i++){
                cout << 0 << ' ';
            }
            for(int i = 0;i < c[2];i++){
                cout << 2 << ' ';
            }
            for(int i = 0;i < c[1];i++){
                cout << 1 << ' ';
            }

            cout << endl;
            continue;
        }
        else{
            cout<< -1 << endl;
        }
    }

    return 0;
}
