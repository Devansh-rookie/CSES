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
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int n;
    fin >> n;
    vector<long long> arr(n);
    for(int i=0;i < n;i++){
        fin >> arr[i];
    }

    for(int i=1;i < n;i++){
        arr[i] = arr[i]+arr[i-1];
    }

    int ans = 0;

    // for(int i=0;i < n;i++){
    //     for(int j = n-1;j >= i;j--){
    //         long long some = (i > 0)?(arr[j] - arr[i-1]): arr[j];
    //         if(some % 7 == 0){
    //             ans = max(ans, j - i + 1);
    //             break;
    //         }
    //     }
    // }
    vector<int> mods(n);
    vector<int> first_repeat(7, -1);
    for(int i=0;i < n;i++){
        mods[i] = arr[i]%7;
        if(first_repeat[mods[i]] == -1) first_repeat[mods[i]] = i;
        else ans = max(ans, i - first_repeat[mods[i]]);
    }

    fout << ans;

    // for(int i=0;i < n;i++){
    //     cout << arr[i] << ' ';
    // }
    return 0;
}