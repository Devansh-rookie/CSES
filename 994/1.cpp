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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i < n;i++){
            cin >> arr[i];
        }
        bool notzero = false;
        for(int i= 0;i < n;i++){
            if(arr[i]){
                notzero = true;
            }
        }
        if(!notzero){
            cout << "0" <<"\n";
            continue;
        }

        int left =0;
        int right = n-1;
        while(left < n && !arr[left]){
            left++;
        }
        while(right >= 0 && !arr[right]){
            right--;
        }

        for(int i = left;i <= right; i++){
            if(!arr[i]){
                cout << "1" << "\n";
                continue;
            }
        }
        cout << "2" <<"\n";
    }
    return 0;
}