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
int n = 3;
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     vector<vector<int>> vals(n, vector<int>(2, 0));
//     for(int i=0;i < n;i++){
//         cin >> vals[i][0] >> vals[i][1];
//     }

//     // first find the length of the thing to make the square
//     long long area = 0; 
//     for(int i=0;i < n;i++){
//         area += vals[i][0]*vals[i][1];
//     }

//     int sq = 1;

//     while (sq * sq < area) { sq++; }
//     if(sq*sq != area){
//         cout << "-1" << "\n";
//         return 0;
//     }
//     // bit masking for all permutations 2^n, go from 0 to 2^n-1
//     // use mask 1<<n
//     for(int mask = 0;mask < 1<<n;mask++){
//         // make a new grid
//         vector<vector<char>> grid(sq, vector<char>(sq, '#'));
//         int placed = 0;
//         bool flag = false;
//         for(int i=0;i < sq && !flag;i++){
//             for(int j=0;j < sq&& !flag;j++){
//                 if(grid[i][j] != '#'){
//                     flag = true;
//                     break;
//                 }
//                 // from bitmask make all permutations
//                 int w = vals[placed][0];
//                 int h = vals[placed][1];
//                 if((1 << placed) & mask){
//                     swap(w, h);
//                 }
//                 bool canPlace = true;
//                 for(int k = i;k < i + w;k++){
//                     for(int m = j;m < j + h;j++){
//                         if(k >= sq|| m >= sq ||grid[k][m] == '#'){
//                             canPlace = false;
//                             break;
//                         }
//                     }
//                     if (!canPlace) break;
//                 }
//                  if (!canPlace) {
//                         flag = true;
//                         break;
//                     }
                
//                 for (int k = i; k < i + h; k++) {
//                         for (int m = j; m < j + w; m++) {
//                             grid[k][m] = placed + 'A';
//                         }
//                     }
//                 placed++;
//             }
//             if(flag) break;
//         }
//         if(placed == n){
//             for(int i=0;i < sq;i++){
//                 for(int j=0;j < sq;j++){
//                     cout << grid[i][j];
//                 }
//                 cout << "\n";
//             }
//             return 0;
//         }
//     }
//     cout << "-1" << "\n";
//     return 0;
// }


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> vals(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        cin >> vals[i][0] >> vals[i][1];
    }

    // Calculate the total area
    long long area = 0;
    for (int i = 0; i < n; i++) {
        area += vals[i][0] * vals[i][1];
    }

    // Find the side of the square
    int sq = 1;
    while (sq * sq < area) sq++;
    if (sq * sq != area) {
        cout << "-1\n";
        return 0;
    }

    // Try all rotations using bitmask
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<vector<char>> grid(sq, vector<char>(sq, '#'));
        int placed = 0;
        bool flag = true;

        for (int i = 0; i < sq && flag; i++) {
            for (int j = 0; j < sq && flag; j++) {
                if (grid[i][j] == '#' && placed < n) {
                    int w = vals[placed][0];
                    int h = vals[placed][1];
                    if ((1 << placed) & mask) swap(w, h);

                    // Check if the logo can be placed
                    bool canPlace = true;
                    for (int k = i; k < i + h; k++) {
                        for (int m = j; m < j + w; m++) {
                            if (k >= sq || m >= sq || grid[k][m] != '#') {
                                canPlace = false;
                                break;
                            }
                        }
                        if (!canPlace) break;
                    }

                    if (!canPlace) {
                        flag = false;
                        break;
                    }

                    // Place the logo
                    for (int k = i; k < i + h; k++) {
                        for (int m = j; m < j + w; m++) {
                            grid[k][m] = placed + 'A';
                        }
                    }
                    placed++;
                }
            }
        }

        if (flag && placed == n) {
            cout << sq << "\n";
            for (int i = 0; i < sq; i++) {
                for (int j = 0; j < sq; j++) {
                    cout << grid[i][j];
                }
                cout << "\n";
            }
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}