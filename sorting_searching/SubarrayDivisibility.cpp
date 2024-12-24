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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i < n;i++) cin >> arr[i];
    map<int , int> freq_map;
    int pref = 0;
    long long ans = 0;
    freq_map[0] = 1;// basically base case whenever the value is 0 add this
    for(int i=0;i < n;i++){
        pref += arr[i];
        int modvalue = (n + pref)%n;// be careful about thihs line
        if(modvalue < 0) modvalue += n;
        ans += freq_map[modvalue];
        freq_map[modvalue]++;
        pref = modvalue;
    }
    cout << ans << endl;
    return 0;
}