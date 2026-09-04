#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 200005;
const int MAXX = 400005;
bool is_sq[MAXN];
vector<int> squares;
vector<pair<int,int>> sum2[MAXX];

void precompute() {
    for(int i = 1; i*i < MAXN; i++) {
        int sq = i*i;
        is_sq[sq] = true;
        squares.push_back(sq);
    }
    for(int u = 0; u*u < MAXX; u++) {
        int u2 = u*u;

        for(int v = u; u2 + v*v < MAXX; v++) {
            sum2[u2 + v*v].push_back({u2, v*v});
        }
    }
}

bool valid3(int w2, int u2, int v2, int a, int b, int n) {
    if(w2 <= a-1 && v2 <= b-1) return true;
    if(u2 <= n-a && v2 <= b-1) return true;
    if(u2 <= n-a && w2 <= n-b) return true;
    if(w2 <= n-a && v2 <= n-b) return true;
    if(u2 <= a-1 && v2 <= n-b) return true;
    if(u2 <= a-1 && w2 <= b-1) return true;

    return false;
}
int main() {
    // setIO("check");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precompute();
    int t;
    cin >> t;
    while(t--) {

        int n, q;
        cin >> n >> q;

        while(q--) {
            int a, b;
            cin >> a >> b;
            if(a > b) swap(a, b);

            int d = b-a;
            if(is_sq[d]) {
                cout << 1 << '\n';
                continue;
            }
            bool dist2 = false;
            for(int sq : squares) {
                if(sq >= d) break;

                if(is_sq[d-sq]) {
                    dist2 = true;
                    break;
                }
            }

            if(!dist2) {
                for(int i = 1; i*i <= n-a; i++) {
                    int sq = i*i;
                    int rem = sq-d;

                    if(rem > 0 && rem < MAXN && is_sq[rem]) {
                        dist2 = true;
                        break;
                    }
                }
            }

            if(!dist2) {
                for(int i = 1; i*i <= a-1; i++) {
                    int sq = i*i;
                    int rem = sq+d;

                    if(rem < MAXN && is_sq[rem]) {
                        dist2 = true;
                        break;
                    }
                }
            }
            if(dist2) {
                cout << 2 << '\n';
                continue;
            }
            bool dist3 = false;

            int x = d;
            while(x % 4 == 0) x /= 4;
            if(x % 8 != 7) {
                dist3 = true;
            }
            else {
                for(int w = 1; w*w <= n; w++) {
                    int w2 = w*w;
                    int X = d+w2;
                    if(X >= MAXX) break;
                    for(auto [u2, v2] : sum2[X]) {
                        if(valid3(w2, u2, v2, a, b, n) || valid3(w2, v2, u2, a, b, n)) {
                            dist3 = true;
                            break;
                        }
                    }
                    if(dist3) break;
                }
                if(!dist3) {
                    for(int w = 1; w*w <= n; w++) {
                        int w2 = w*w;
                        int X = w2-d;
                        if(X <= 0 || X >= MAXX) continue;
                        for(auto [u2, v2] : sum2[X]) {
                            if(valid3(w2, u2, v2, a, b, n) || valid3(w2, v2, u2, a, b, n)) {
                                dist3 = true;
                                break;
                            }
                        }
                        if(dist3) break;
                    }
                }
            }
            cout << (dist3 ? 3 : 4) << '\n';
        }
    }
    return 0;
}