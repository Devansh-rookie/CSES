#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> arr(n+1);
    vector<long long> addition(n+2, 0);
    for(int i = 1;i <= n;i++) cin >> arr[i];

    vector<vector<int>> oper(m+1, vector<int>(3));
    for(int i = 1;i <=m;i++){
        cin >> oper[i][0] >> oper[i][1] >> oper[i][2];
    }

    vector<int> queries(m+2, 0);
    for(int i = 1;i <= k;i++){
        int x, y;
        cin >> x >> y;
        queries[x]++;
        queries[y+1]--;
    }

    for(int i = 1;i <= m;i++){
        queries[i] += queries[i-1];
        // queries[i] is how many times you have to excecute it(the query i) on that so multiply x and y+1 with this
        int x = oper[i][0];
        int y = oper[i][1];
        int d = oper[i][2];

        // apply the query
        addition[x] += (long long)d*queries[i];
        addition[y+1] -= (long long)d*queries[i];
    }

    for(int i = 1;i <= n;i++){
        addition[i] += addition[i-1];
        cout << arr[i] + addition[i] << ' ';
    }
    return 0;
}