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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(2*n);
    for(int i=0;i < 2*n;i++){
        cin >> arr[i];
    }

    int ans = INT_MAX;
    sort(arr.begin(), arr.end());
    // keep everything in single kayaks atleast once
    for(int i = 0;i < 2*n;i++){
        for(int j = i+1;j < 2*n;j++){
            vector<int> narr(2*n-2);
            int c = 0;
            for(int k = 0;k < 2*n;k++){
                if(k != i && k != j) narr[c++] = arr[k];
            }

            int temp = 0;

            for(int k = 0;k < 2*n - 2;k+=2){
                temp += narr[k+1] - narr[k];
            }
            ans = min(temp, ans);
        }
    }
    cout << ans << "\n";
    return 0;
}