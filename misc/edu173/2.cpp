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
        int n, d;
        cin >> n >> d;
        cout << 1 << ' ';
        if(n >= 3 || d %3 == 0){
            cout << 3 << ' ';
        }
        if(d == 5){
            cout << 5 << ' ';
        }
        if(d == 7 || n >= 3){
            cout << 7 << ' ';
        }
        if(d == 9 || n>=6 || (d%3==0 && n>=3)){
            cout << 9 << ' ';
        }
        cout << endl;
    }
    return 0;
}