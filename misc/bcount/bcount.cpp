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
    ifstream fin("bcount.in");
    ofstream fout("bcount.out"); 
    
    int number_of_breeds = 3;

    int n, q;
    fin >> n >> q;

    vector<vector<int>> arr(4, vector<int>(n+1, 0));

    for(int i=1;i <= n;i++){
        int val;
        fin >> val;
        arr[val][i] = 1;
    }

    for(int i=1;i <= number_of_breeds;i++){
        for(int j = 2;j <= n;j++){
            arr[i][j] += arr[i][j-1];
        }
    }

    for(int i = 0;i < q;i++){
        int l, r;
        fin >> l >> r;
        for(int j = 1;j <= number_of_breeds;j++){
            fout << arr[j][r] - arr[j][l-1];
            if(j != number_of_breeds) fout << ' '; 
        }
        fout << endl;
    }

    return 0;
}   