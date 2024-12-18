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


#define MOD 1000000007


using namespace std;

long long myPow(long x, int n) {
    if(x==0) return 0.0;
    else if(n==0||x==1) return 1.0;
    long long a= myPow(x,n/2);
    if(n%2==0){
        return (long long)a*a%(long long)MOD;
    }
    else{
        if(n>0) return (long long)x*a*a%(long long)MOD;
        else return (((long long)(a*a)%(long long)MOD)/(long long)x)%(long long)MOD;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << myPow(2, n) <<endl;
    return 0;
}