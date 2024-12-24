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

long long solve(long long n){
    // if(n <= 4) return 1;
    // return 2*solve(n/4);
    long long curr = 1;
    while(n>=4){
        curr = 2*curr;
        n = n/4;
    }
    return curr;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cout << solve(n)<< '\n';
    }
    return 0;
}