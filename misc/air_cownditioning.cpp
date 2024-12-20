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

vector<bool> uses;
vector<vector<int>> cows;
vector<vector<int>> acs;
int ans = 1e6;
int N, M;


void solve(){
    // vector<int> cooling(101, 0);
    bool not_done = false;
    for(int i=1;i <= 100;i++){
        int cool = 0; // find coolinbg at that point and compare to the cow at that point as cows can't be more
        for(int j=0;j < M;j++){
            if(uses[j]){
                int a = acs[j][0];
                int b = acs[j][1];
                int c = acs[j][2];
                if(a <=  i && i <= b){
                    cool += c;
                }
            }
        }
        // now find the cow
        int cow = 0;
        for(int j=0;j < N;j++){
            int left = cows[j][0];
            int right = cows[j][1];
            int require = cows[j][2];
            if(left <= i && right >= i){
                cow = require;
                break;
            }
        }

        if(cool < cow){
            not_done = true;
            break;
        }
    }
    if(!not_done){
        int some = 0;
        for(int i=0;i < M;i++){
            if(uses[i]) some += acs[i][3];
        }
        ans = min(ans, some);
    }
}


void helpp(int index){
    // index of the AC to select or reject
    if(index == M){
        solve();
        return;
    }
    // select the index
    uses[index] = true;
    helpp(index+1);
    // deselect
    uses[index] = false;
    helpp(index+1); 
}

int main()
{
    int n, m;
    cin >> n >> m;
    cows.resize(n, vector<int>(3));
    for(int i=0; i < n;i++){
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    acs.resize(m, vector<int>(4));
    for(int i=0; i < m;i++){
        cin >> acs[i][0] >> acs[i][1] >> acs[i][2] >> acs[i][3];
    }
    
    uses.resize(m, false);
    ans = 1e6;
    N = n;
    M = m;
    helpp(0);// select or unselect here 
    cout << ans <<endl;
    return 0;
}