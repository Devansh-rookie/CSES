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

void toh(int n, char s, char a, char d){
    if(n == 1){
        cout << s << " " << d << endl;
    }
    else{
        toh(n-1, s, d, a);
        cout << s << " " << d << endl;
        toh(n-1, a, s, d);
    }
}

int main()
{
    cin.tie(0);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 <<endl;
    toh(n, '1', '2', '3');
    return 0;
}