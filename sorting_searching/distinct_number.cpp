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
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<int> ans(n);
    for(int i=0;i < n;i++){
        cin >> ans[i];
    }
    sort(ans.begin(), ans.end());
    int node = 1;
    for(int i=1; i < n;i++){
        if(ans[i]!= ans[i-1]){
            node++;
        }
    }
    cout << node << endl;
    return 0;
}