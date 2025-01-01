#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ans = 0;
    map<long long, long long> m;
    m[0] = 1;
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i];

    long long suma = 0;
    for(int i = 0;i < n;i++){
        suma += arr[i];
        ans += m[suma - x];
        m[suma]++;
    }
    cout << ans << endl;
    return 0;
}