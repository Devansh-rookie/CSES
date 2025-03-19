#include <algorithm>
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

void solve(int n){
    vector<long long> b(2*n, 0);
    for(int i = 0;i < 2*n;i++)cin >> b[i];
    set<long long> bs(b.begin(), b.end());
    sort(b.begin(), b.end());
    vector<long long>pos(n, 0);
    vector<long long> neg(n, 0);
    long long nega = 0;
    long long posi = 0;
    for(int i = 0;i < n;i++){
        neg[i] = b[i];
        nega += b[i];
    }

    for(int i = 0;i < n;i++){
        pos[i] = b[n + i];
        posi += b[n+i];
    }

    long long s = posi - nega;
    if(bs.find(s) == bs.end()){
        // print here, with S as a1
        cout << s << ' ';
        int itp = 0;
        int itn = 0;
        for(int j = 0;j < 2*n;j++){
            if(j%2 == 0){
                cout << pos[itp++] << ' ';
            }
            else cout << neg[itn++] << ' ';
        }
        cout << endl;
        return;
    }
    long long s_old = s;
    // swawp at most n times
    for(int i = 0;i < n;i++){
        s = s_old + 2*(neg[i] - pos[i]);
        swap(neg[i], pos[i]);
        if(bs.find(abs(s)) == bs.end()){
            // print here, with S as a1
            cout << s << ' ';
            int itp = 0;
            int itn = 0;
            for(int j = 0;j < 2*n;j++){
                if(j%2 == 0){
                    cout << pos[itp++] << ' ';
                }
                else cout << neg[itn++] << ' ';
            }
            cout << endl;
            return;
        }
        swap(neg[i], pos[i]);
    }

    // reverse(neg.begin(), neg.end());
    while(next_permutation(neg.begin(), neg.end())){

        for(int i = 0;i < n;i++){
            s = s_old + 2*(neg[i] - pos[i]);
            swap(neg[i], pos[i]);
            if(bs.find(abs(s)) == bs.end()){
                // print here, with S as a1
                cout << s << ' ';
                int itp = 0;
                int itn = 0;
                for(int j = 0;j < 2*n;j++){
                    if(j%2 == 0){
                        cout << pos[itp++] << ' ';
                    }
                    else cout << neg[itn++] << ' ';
                }
                cout << endl;
                return;
            }
            swap(neg[i], pos[i]);
        }

        s = s_old;
    }



    cout << -1;
}


int main() {
    // setIO("check");

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
