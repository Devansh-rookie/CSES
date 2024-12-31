#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    long long ans = 0;
    cin >> n >> q;
    vector<int> arr(n+1, 0);
    for(int i = 1;i <= n;i++) cin >> arr[i];
    sort(arr.begin()+1, arr.end());
    vector<long long> queries(n+2, 0);
    for(int i = 1;i <= q;i++){
        int x, y;
        cin >> x >> y;
        queries[x]++;
        queries[y+1]--;
    }

    for(int i = 1;i <= n;i++) queries[i] += (long long)queries[i-1];
    sort(queries.begin() + 1, queries.end() - 1);
    // the queries array tells us how many times the index is repeated in all the queries there we sort it and multiply max value with max value which works
    // else do it with BIT(Binary Indexed Trees)
    for(int i = 1;i <= n;i++) ans += (long long)arr[i]*queries[i];
    cout << ans << endl;
    return 0;
}