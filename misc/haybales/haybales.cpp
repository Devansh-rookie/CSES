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
    setIO("haybales");
    int n, q;
    cin >> n >> q;
    vector<int> arr(n, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;

        cout << upper_bound(arr.begin(), arr.end(), b) - lower_bound(arr.begin(), arr.end(),a) << endl;
    }

    return 0;
}