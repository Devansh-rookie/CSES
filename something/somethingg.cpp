#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> prime(int n)
{
    const int N = n;
    vector<int> lpf(N + 1);

    for (int i = 2; i <= N; i++)
    {
        if (lpf[i] == 0)
        { // i is prime
            for (int j = i; j <= N; j += i)
            {
                lpf[j] = i;
            }
        }
    }

    return lpf;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<int> lpf = prime(200005);

ll solve(int n, int k, vector<ll> &arr)
{
    ll ans = 0;

    // vector<int> lpf = prime(n);

    for (int i = n; i > k; i--)
    {
        int x = i;
        ll cnt = arr[i];
        if (cnt == 0)
            continue;

        int val = x / lpf[x];
        ans += cnt;
        if (val > k)
        {
            arr[val] += cnt * lpf[x];
        }
    }

    return ans;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    setIO("check");
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int k;
        cin >> k;

        vector<ll> a(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x > k)
            {
                a[x]++;
            }
        }
        cout << solve(n, k, a) << "\n";
    }

    return 0;
}
