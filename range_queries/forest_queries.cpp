// #include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            char c;
            cin >> c;
            if(c == '*'){
                arr[i][j] = 1;
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    for(int i = 0;i < q;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1] << endl;
    }

    return 0;
}