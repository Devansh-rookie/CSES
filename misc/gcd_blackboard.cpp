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

int gcd(int a, int b)
{

    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i < n;i++) cin >> arr[i];

    vector<int> pgcd(n+2); // prefix gcd
    vector<int> sgcd(n+2); // suffix gcd

    pgcd[0] = 0;
    sgcd[0] = 0;
    //gcd(0, X) = X

    sgcd[n+1] = 0;
    pgcd[n+1] = 0;

    
    for(int i = 1;i <= n;i++){
        pgcd[i] = gcd(pgcd[i-1], arr[i-1]);
    }

    for(int i = n;i >= 1;i--){
        sgcd[i] = gcd(sgcd[i+1], arr[i-1]);
    }

    // just the value where i is there look around it how its changing and stuff

    int ans = 0;
    for(int i=1;i <= n;i++){
        ans = max(ans, gcd(sgcd[i+1], pgcd[i-1]));
    }

    // for(int i: pgcd) cout << i << ' ';
    // cout << '\n';
    // for(int i: sgcd) cout << i << ' ';
    // cout << '\n';

    cout << ans << '\n';
    return 0;
}