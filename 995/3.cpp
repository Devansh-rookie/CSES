#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>  
#include <vector>
#include <list>        
#include <set> 
#include <map>    
#include <queue> 
#include <stack>
#include <algorithm>  
#include <cmath> 
#include <ctime> 
#include <cstdlib>
#include <cstring> 
#include <cctype> 
#include <cassert>
#include <exception>   
#include <functional>
#include <iterator>
#include <limits>  
#include <locale>   
#include <numeric>  
#include <random> 
#include <stdexcept> 
#include <typeinfo> 
#include <utility>
#include <unordered_set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m , k;
        cin >> n >> m >> k;
        
        vector<int> missing(m);
        for(int i=0;i < m;i++){
            cin >> missing[i];
        }

        set<int> kk;
        int doesnk =n+1;
        for(int i=0;i < k;i++){
            int val;
            cin >> val;
            kk.insert(val);
        }

        if(n == k){
            for(int i=0;i < m;i++){
                cout << 1;
            }
            cout << '\n';
            continue;
        }

        if(k <= n-2){
            for(int i=0;i < m;i++){
                cout << 0;
            }
            cout << '\n';
            continue;
        }

        for(int i=1;i <= n;i++){
            if(kk.find(i) == kk.end()){
                doesnk = i;
                break;
            }
        }

        for(int i=0;i < m;i++){
            if(doesnk == missing[i]){
                cout << 1;
            }
            else cout << 0;
        }
        cout << endl;
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include<set>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     while(t--){
//         int n, m, k;
//         cin >> n >> m >> k;

//         vector<int> missing(m);
//         for(int i = 0; i < m; ++i){
//             cin >> missing[i];
//         }

//         // unordered_set<int> known_questions;
//         // for(int i = 0; i < k; ++i){
//         //     int q;
//         //     cin >> q;
//         //     known_questions.insert(q);
//         // }

//         vector<int> known_questions(k);

//         for(int i = 0; i < k; ++i){
//             cin >> known_questions[i];
//         }

//         set<int> some(known_questions.begin(), known_questions.end());

//         for(int i=1;i <= n;i++){
//             if
//         }

//         string result(m, '0');
//         for(int i = 0; i < m; ++i){
//             int skipped = missing[i]; 
//             bool can_pass = true;

//             for(int j = 1; j <= n; ++j){
//                 if (j != skipped && known_questions.find(j) == known_questions.end()) {
//                     can_pass = false;
//                     break;
//                 }
//             }

//             if(can_pass){
//                 result[i] = '1';
//             }
//         }

//         cout << result << '\n';
//     }

//     return 0;
// }
