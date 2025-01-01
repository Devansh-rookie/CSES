#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int binarySearch(vector<pii> &arr, int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid].first == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid].first < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<pii> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            int index = binarySearch(arr, 0, n-1,x - arr[i].first - arr[j].first);
            if(index != -1 && i != index && j != index){
                cout << arr[i].second + 1 << ' '<< arr[j].second + 1 << ' '<<arr[index].second + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}