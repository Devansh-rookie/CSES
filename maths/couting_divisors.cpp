#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int arr[N+1];
void sieve(){
    for(int i = 2;i <= N;i++){
        if(!arr[i]){
            for(int j = i;j <= N;j+=i){
                arr[j] = i; // largest prime number dividing j then we will check it again and again by dividing
            }
        }
    }
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

long long some(int x){
    long long ans = 1;
    while(x != 1){
        // max prime first then x would change
        int max_prime_dividing_x = arr[x];
        int alpha_i = 0;

        while(x % max_prime_dividing_x == 0){
            x /= max_prime_dividing_x;
            alpha_i++;
        }

        ans *= (alpha_i + 1);
    }
    return ans;
}

int main() {
    // setIO("check");
    sieve();
    int n;
    cin >> n;

    // for(int j = 0;j < n;j++){
    //     int x;
    //     cin >> x;
    //     long long ans = 0;
    //     int i = 1;
    //     for(i = 1;i * i < x;i++){
    //         if(x%i == 0) ans+=2; // since every factor would have 2 like 3 * 4 == 12, but we will onyl check till the sqaure root to be smart as afgter that it will start repeating but we might find it at a distance more than what we found in here as root(x) is less than x - root(x) if we check above root x it would be a waste of time one is like searching for people in a desert the other is like searching in a city 
    //     }
    //     if(i * i == x) ans++; // if x is a perfect square then ans would be incremented by 1 only as it has 2 same factors
    //     cout << ans << endl;
    // }

     for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        cout << some(x) << endl;
     }

    return 0;
}