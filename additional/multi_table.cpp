#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) x.begin(), x.end()
using ll = long long;

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

    ll n;
    cin >> n;
    // cout << (n - (n/2) + 1)*(n/2);

    // high = n^2 and low = 1;

    ll high = n*n;

    ll low = 1;
    ll mid;
    while(low < high){
        // mid and mid + 1, as it would be a monotonically increasing function
        // we need the minimum x which is greater than (n*n + 1)/2
        mid = (low + high)/2;
        ll how_many_are_less = 0;
        // go from 1 to n rows and find how many number are smaller than or eqaul to the current mid
        for(int i = 1;i <= n;i++){
            // or suma += min(mid/i, n);
            if(mid >= i*n){
                how_many_are_less += n;
            }
            else{
                // add the i till which mid is greater than or equal to
                // i*j = some then j = mid/i; GIF is the thing
                how_many_are_less += mid/i;
            }
        }

        // ____----
        // this is the type of function so we need to find the breaking point by mid + 1 and bound it by mid from high if it satisfies

        if((n*n + 1)/2 <= how_many_are_less){ // that is basically exact half
            high = mid;// make it smaller 
        }
        else low = mid + 1; // make it larger 
    }

    cout << low; // low == high in the end I think??

    return 0;
}