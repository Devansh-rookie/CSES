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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i < n;i++){
        cin >> arr[i];
    }
    // unordered_map<long long, int> freq_map; // unordered mapp would not work because of collisions
    map<long long, int> freq_map;
    freq_map[0] = 1; // empty subarray sum basically
    long long suma = 0; // prefix sum
    long long ans = 0;
    for(int i=0;i < n;i++){
        suma += arr[i];

        ans += freq_map[suma - x];

        freq_map[suma]++;
    }
    cout << ans << endl;
    return 0;
}