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
using pii = pair<int, int>;

int binarys(int tar, vector<pii> & arr){
    int low = 0;
    int n = arr.size();
    int high = n - 1;
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(arr[mid].first == tar){
            return mid;
        }
        else if(arr[mid].first > tar){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pii> arr(n);
    for(int i=0;i < n;i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    for(int i=0;i < n;i++){
        int search = binarys(x - arr[i].first, arr);
        if(search != -1 && search != i){
            cout << arr[i].second + 1<< ' '<< arr[search].second + 1<< "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    
    return 0;
}