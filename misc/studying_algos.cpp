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

    int n, x;

    cin >> n >> x;
    vector<int> arr(n);

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int suma = 0;
    int ans = 0;
    for(int i = 0;i < n && suma + arr[i]<= x;i++){
        suma += arr[i];
        ans++;
    }

    cout << ans;

    return 0;
}
