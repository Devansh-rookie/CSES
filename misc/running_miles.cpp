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
        vector<int> arr(n+1); // for bi2
        for(int i=0;i < n;i++) cin >> arr[i+1];
        vector<int> pmax(n+1); // for bi1, prefix max
        vector<int> smax(n+1); // for bi3, suffix max

        for(int i = 1;i <= n;i++){
            pmax[i] = arr[i] + i; // for +l in the term -(r-l)
            smax[i] = arr[i] - i; // for -r in the term -(r-l)
        }

        int ans = INT_MIN;

        for(int i = 2;i <= n;i++) pmax[i] = max(pmax[i], pmax[i-1]);
        for(int i = n-1;i >= 1;i--) smax[i] = max(smax[i], smax[i+1]);

        for(int i = 1;i <=n-1;i++){
            ans = max(ans, pmax[i-1] + arr[i] + smax[i+1]);
        }

        cout << ans << endl;
    }
    return 0;
}