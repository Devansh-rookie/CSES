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
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> arr(n+1);
        arr[0] = 0;
        for(int i=1;i <= n;i++){
            char c;
            cin >> c;
            arr[i] = (long long)(c - '0');
        }

        map<long long, int> times_pi_i;
        // use map instead of unordered_map here as its a bit more fool pproof of TLE stuff O(logn) but worth it in the long run
        for(int i = 1;i <= n;i++) arr[i] += arr[i-1];
        // using i = 0 already adds the base case of times_pi_i[0] = 1;
        for(int i = 0;i <= n;i++){
            times_pi_i[arr[i] - i]++;
        }
        long long ans = 0;
        for(auto &[keys, vals] : times_pi_i){
            ans += (long long)vals*(vals-1)/2;
        }
        cout << ans << '\n';
    }
    return 0;
}