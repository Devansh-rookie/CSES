#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to compute GCD of two numbers
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// long long gcd(long long a, long long b)
// {
//     /* GCD(0, b) == b; GCD(a, 0) == a,
//     GCD(0, 0) == 0 */
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;

//     /*Finding K, where K is the
//     greatest power of 2
//     that divides both a and b. */
//     long long k;
//     for (k = 0; ((a | b) & 1) == 0; ++k) 
//     {
//         a >>= 1;
//         b >>= 1;
//     }

//     /* Dividing a by 2 until a becomes odd */
//     while ((a & 1) == 0)
//         a >>= 1;

//     /* From here on, 'a' is always odd. */
//     do
//     {
//         /* If b is even, remove all factor of 2 in b */
//         while ((b & 1) == 0)
//             b >>= 1;

//         /* Now a and b are both odd.
//         Swap if necessary so a <= b,
//         then set b = b - a (which is even).*/
//         if (a > b)
//         {
//             long long tmp = a; // Swap u and v.
//             a = b;
//             b = tmp;
//         }
//         b = (b - a);
//     }while (b != 0);

//     /* restore common factors of 2 */
//     return a << k;
// }


void solve() {
    int t;
    cin >> t;

    while (t--) {
        long long l, r, G;
        cin >> l >> r >> G;

        long long A = ((l + G - 1) / G) * G; 

        long long B = (r / G) * G;
        while (A <= B && gcd(A, B) != G) {
            B = B - G; 
        }

        if (A > B) {
            cout << "-1 -1" << endl;
        } else {
            cout << A << " " << B << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}