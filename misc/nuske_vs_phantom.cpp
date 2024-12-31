#include<bits/stdc++.h>
using namespace std;

// vector <int> integerToArray(int x)
// {
//     vector <int> resultArray;
//     while (true)
//     {
//     resultArray.insert(resultArray.begin(), x%10);
//     x /= 10;
//     if(x == 0)
//         return resultArray;
//     }
// }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> arr(n+2, vector<int>(m+2, 0));
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            // this is important, like very important to take input in the form of characters
            char c;
            cin >> c;
            c = c - '0';
            arr[i][j] = c;
        }
    }

    vector<vector<int>> pref(n+2, vector<int>(m+2, 0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            if(!arr[i][j]) continue;
            if((!arr[i-1][j]) && (!arr[i][j-1])){
                pref[i][j]++;
            }
            else if(arr[i][j-1] && arr[i-1][j]) pref[i][j]--;
        }
    }

    // ofstream fout("test.out");

    // for(vector<int> i: pref){
    //     for(int j: i){
    //         fout << j << ' ';
    //     }
    //     fout << endl;
    // }

    vector<vector<int>> hori(n+2, vector<int>(m+2, 0));
    vector<vector<int>> vert(n+2, vector<int>(m+2, 0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            hori[i][j] = hori[i][j-1];
            vert[i][j] = vert[i-1][j];

            if(arr[i][j]){
                hori[i][j] += arr[i][j-1]?0:1;
                vert[i][j] += arr[i-1][j]?0:1;
            }
        }
    }

    for(int i = 0;i < q;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long ans = 0;

        ans = arr[x1][y1];

        ans += hori[x1][y2] - hori[x1][y1];
        ans += vert[x2][y1] - vert[x1][y1];

        cout << ans + pref[x2][y2] - pref[x2][y1] - pref[x1][y2] + pref[x1][y1] << endl;
        // remove the -1's as we need the mergnings belowe it and no the ones we are already looking at 
        // fout << pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1];
    }

    return 0;
}