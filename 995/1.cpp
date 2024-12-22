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
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for(int i=0;i < n;i++){
            cin >> a[i];
        }
        for(int i=0;i < n;i++){
            cin >> b[i];
        }
        if(n == 1){
            cout << a[0] << endl;
            continue;
        }
        int ans = 0;
        for(int i=0;i < n;i++){
            if(i + 1 < n && a[i] > b[i+1]){
                ans += a[i] - b[i+1];
            }
        }
        ans += a[n-1];
        cout << ans << endl;
    }
    return 0;
}