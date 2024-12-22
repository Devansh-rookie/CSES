// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <iomanip>
// #include <string>  
// #include <vector>
// #include <list>        
// #include <set> 
// #include <map>    
// #include <queue> 
// #include <stack>
// #include <algorithm>  
// #include <cmath> 
// #include <ctime> 
// #include <cstdlib>
// #include <cstring> 
// #include <cctype> 
// #include <cassert>
// #include <exception>   
// #include <functional>
// #include <iterator>
// #include <limits>  
// #include <locale>   
// #include <numeric>  
// #include <random> 
// #include <stdexcept> 
// #include <typeinfo> 
// #include <utility>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--){
//         int n, k;
//         cin >> n >> k;
//         vector<int>a(n);
//         vector<int>b(n);
//         for(int i=0;i < n;i++) cin >> a[i];
//         for(int i=0;i < n;i++) cin >> b[i];


//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to determine if a given price can fit in at least `n-k` intervals
bool canKeepPrice(const vector<pair<int, int>>& intervals, int price, int needed) {
    int count = 0;
    for (const auto& interval : intervals) {
        if (interval.first <= price && price <= interval.second) {
            count++;
        }
        if (count >= needed) return true; // Early termination
    }
    return count >= needed;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> intervals(n);
        vector<int> allPrices;

        for (int i = 0; i < n; i++) {
            cin >> intervals[i].first; // a[i]
        }
        for (int i = 0; i < n; i++) {
            cin >> intervals[i].second; // b[i]
        }

        // Collect all unique interval endpoints for binary search
        for (const auto& interval : intervals) {
            allPrices.push_back(interval.first);
            allPrices.push_back(interval.second);
        }

        // Sort the intervals and unique prices
        sort(intervals.begin(), intervals.end());
        sort(allPrices.begin(), allPrices.end());
        allPrices.erase(unique(allPrices.begin(), allPrices.end()), allPrices.end());

        int needed = n - k; // Minimum intervals where price must be valid
        int maxPrice = 0;

        // Binary search over all unique prices
        int left = 0, right = allPrices.size() - 1;
        while (left <= right) {
            int midIndex = (left + right) / 2;
            int candidatePrice = allPrices[midIndex];

            if (canKeepPrice(intervals, candidatePrice, needed)) {
                maxPrice = candidatePrice;
                left = midIndex + 1; // Try for a higher price
            } else {
                right = midIndex - 1; // Reduce the price range
            }
        }

        cout << maxPrice << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
