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
//         string s;
//         int n;
//         cin >> n;
//         cin >> s;
//         s = "." + s;
//         if(s[1] == 'p' && s[n] == 's'){
//             cout << "NO" << "\n";
//         }
//         string p = "";
//         string ss = "";
//         string dot = "";
//         for(int i=0;i < n;i++){
//             p += 'p';
//             ss += 's';
//             dot += '.';
//         }
//         if(p == s || s == ss || dot == s){
//             cout << "YES";
//             continue;
//         }


//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool is_valid_permutation(const string &s) {
    int n = s.size();
    vector<bool> prefix_valid(n + 1, true);
    vector<bool> suffix_valid(n + 1, true);
    
    // Check prefix validity
    unordered_set<int> seen;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 's') break;
        seen.insert(i);
        if ((int)seen.size() != i) {
            prefix_valid[i] = false;
            break;
        }
    }

    // Check suffix validity
    seen.clear();
    for (int i = n; i >= 1; --i) {
        if (s[i - 1] == 'p') break;
        seen.insert(n - i + 1);
        if ((int)seen.size() != n - i + 1) {
            suffix_valid[i] = false;
            break;
        }
    }

    // Check all constraints
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'p' && !prefix_valid[i]) return false;
        if (s[i - 1] == 's' && !suffix_valid[i]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (is_valid_permutation(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
