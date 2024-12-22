// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <iomanip>
// #include <string>  
// #include <vector>
// #include <list>        
// #include <set> 
// #include <map>    
// #include <queue> 
// #include <stack>
// #include <algorithm>  
// #include <cmath> 
// #include <ctime> 
// #include <cstdlib>
// #include <cstring> 
// #include <cctype> 
// #include <cassert>
// #include <exception>   
// #include <functional>
// #include <iterator>
// #include <limits>  
// #include <locale>   
// #include <numeric>  
// #include <random> 
// #include <stdexcept> 
// #include <typeinfo> 
// #include <utility>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--){
//         long n, a, b, c;
//         cin >> n >> a >> b >> c;

//         int val = n/(a+b+c);

//         long some = (n-1)*(a+b+c);
//         if(a+some >= n){
//             cout << val*3 + 1 << endl;
//             continue;
//         }
//         some += a;
//         if(b+some >= n){
//             cout << val*3 + 2 << endl;
//             continue;
//         }
//         some += b;
//         if(c+some >= n){
//             cout << val*3 + 3 << endl;
//             continue;
//         }
//         cout << "-1";
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;

        long long cycle_sum = a + b + c;
        long long full_cycles = n / cycle_sum;
        long long distance_covered = full_cycles * cycle_sum;

        long long days = full_cycles * 3;

        long long remaining = n - distance_covered;

        if (remaining > 0) {
            if (remaining <= a) {
                days += 1;
            } else if (remaining <= a + b) {
                days += 2;
            } else {
                days += 3;
            }
        }

        cout << days << endl;
    }

    return 0;
}
