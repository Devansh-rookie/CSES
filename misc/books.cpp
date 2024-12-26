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
    int n, t;
    cin >> n >> t;
    vector<int> arr(n+1);
    for(int i=0;i < n;i++) cin >> arr[i+1];

    int l = 1;
    int r = 1;
    int ans = 0;
    while(r <= n){
        if(t >= arr[r]){
            t-=arr[r];
            r++;
        }
        else{
            t+= arr[l];
            l++;
        }
        ans = max(ans, r-l);
    }
    cout << ans << endl;
    return 0;
}