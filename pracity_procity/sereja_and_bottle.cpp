// #include<bits/stdc++.h>
// using namespace std;

// void setIO(string name = "") {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     if (name.size()) {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

// int main() {
//     setIO("check");

//     int n;
//     cin >> n;

//     vector<int> a(n);
//     vector<int> b(n);

//     for(int i = 0;i < n;i++){
//         cin >> a[i] >> b[i];
//     }

//     // can be opened by;

//     map<int, set<int> > cbob;
//     map<int, int> freq;
//     for(int i = 0;i < n;i++){
//         freq[a[i]]++;
//         cbob[b[i]].insert(a[i]);
//     }

//     set<int> opened;

//     for(auto it: cbob){
//         set<int> curr = it.second;
//         if(curr.size() == 1 && *curr.begin() == it.first){
//             if(freq[*curr.begin()] > 1){
//                 opened.insert(*curr.begin());
//             }
//         }
//         else{
//             for(auto vals: curr){
//                 if(freq[vals] >= 1 && vals != it.first){
//                     opened.insert(it.first);
//                     break;
//                 }
//                 else if(vals == it.first){
//                     if(freq[vals] > 1){
//                         opened.insert(it.first);
//                         break;
//                     }
//                 }
//             }
//         }
//     }

//     int ans = n;

//     for(int i = 0;i < n;i++){
//         if(opened.find(a[i]) != opened.end()){
//             ans--;
//         }
//     }
//     cout << ans;
//     return 0;
// }


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

int main() {
    // setIO("check");

        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0;i < n;i++){
            cin >> a[i] >> b[i];
        }

    vector<bool>can_open(n, false);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j) continue;
            if(a[i] == b[j]){
                can_open[i] = true;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(can_open[i] == false){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
