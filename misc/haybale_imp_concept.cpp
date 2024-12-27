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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n+2, 0);
    long long suma = 0;
    for(int i=0;i < k;i++){
        int r, l;
        cin >> l >> r;
        arr[l] += 1;
        arr[r+1] -= 1;
    }

    for(int i=0;i <= n;i++){
        suma += arr[i];
        arr[i] = suma;
    }

    sort(arr.begin() + 1, arr.end() - 1);

    if(n%2 == 0){
        cout << (arr[n/2+1] + arr[n/2 + 2])/2 << endl;
    }
    else{
        cout << arr[n/2 + 1] << endl;
    }
    return 0;
}