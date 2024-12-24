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
    int n, q;
    cin >> n >> q;
    vector<long> arr(n);
    for(int i=0;i < n;i++){
        cin >> arr[i];
    }

    for(int i=1;i < n;i++){
        arr[i] = arr[i]+arr[i-1];
    }

    vector<long> ans(q);

    for(int i=0;i < q;i++){
        int l, r;
        cin >> l >> r;
        ans[i] = (l > 0)?(arr[r-1] - arr[l-1]): arr[r-1];
    }

    for(long i: ans) cout << i << endl;
    return 0;
}