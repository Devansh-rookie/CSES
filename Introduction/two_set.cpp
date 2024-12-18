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
    vector<int> s1, s2;
    if(n%4 == 0 || n%4 == 3){
        long long req_sum = (long long)n*(n+1)/4;
        for(int i = n;i > 0;i--){
            if(req_sum >= i){
                req_sum -= i;
                // cout << i << " ";
                s1.push_back(i);
            }
            else{
                // cout << i << " ";
                s2.push_back(i);
            }
        }
    }
    else{
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << s1.size() << endl;
    for(int i: s1){
        cout << i << " ";
    }
    cout << endl;
    cout << s2.size() << endl;
    for(int i: s2){
        cout << i << " ";
    }
    return 0;
}