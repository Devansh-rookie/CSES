#include<bits/stdc++.h>
#include <vector>
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

    int t;

    cin >> t;

    while(t--){
        int n, x;

        cin >> n >> x;

        vector<int> arr(n, 0);
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }

        long long suma = 0;

        for(int i = 0;i < n;i++){
            suma += arr[i];
        }

        if(suma/(double)n == x){
            cout << "YES" <<endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}


/*
def find_valid_sum(arr):
    arr.sort()  # Sort the given numbers
    n = len(arr) // 2

    # Step 1: Compute initial sum
    pos = arr[n:]   # Larger half as positive
    neg = arr[:n]   # Smaller half as negative
    S = sum(pos) - sum(neg)

    # Step 2: Ensure S is not in the given numbers
    if S not in arr:
        return S

    # Step 3: Apply a tweak by swapping an adjacent pair
    for i in range(n):
        new_pos = pos.copy()
        new_neg = neg.copy()

        # Swap the smallest positive with the largest negative
        new_pos[i], new_neg[-1-i] = new_neg[-1-i], new_pos[i]
        S_new = sum(new_pos) - sum(new_neg)

        if S_new not in arr:
            return S_new

    return None  # This should never happen with distinct numbers

# Example usage
given_numbers = [1, 3, 5, 7, 9, 11]
result = find_valid_sum(given_numbers)
print("Valid sum not in the given numbers:", result)

*/
