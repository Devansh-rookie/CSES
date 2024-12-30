// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     ifstream fin("lazy.in");
//     ofstream fout("lazy.out");

//     int n, k;
//     fin >> n >> k;
//     vector<vector<int>> ogarr(n+1, vector<int>(n+1, 0));
//     vector<vector<int>> arrnew(2*n+1, vector<int>(2*n+1, 0));

//     for(int i=1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             fin >> ogarr[i][j];
//         }
//     }

//     int space = n - 1;
//     int j = 1;
//     for(int c = 2;c <= n+1;c++){
//         vector<int> node(c+2);
//         int k = 1;
//         for(int x = c-1; x >= 1;x--){
//             node[k++] = ogarr[x][c-x];
//         }
//         // cout << k;
//         k = 1;
//         for(int i = space + 1;k <= c;){
//             arrnew[j][i] = node[k];
//             // k += 2;
//             k++;
//             i+=2;
//         }
//         j++;
//         space--;
//     }
//     space = 1;
//     for(int c = n+2;c <= 2*n;c++){
//         vector<int> node(c - n + 2);
//         int k = 1;
//         for(int x = c-1; x >= 1;x--){
//             node[k++] = ogarr[x][c-x];
//         }
//         k = 1;
//         for(int i = space + 1;k <= c - n;){
//             arrnew[j][i] = node[k];
//             k ++;
//             i+=2;
//         }
//         j++;
//         space++;
//     }

//     printarr(arrnew);
//     return 0;
// }

// // #include <bits/stdc++.h>
// // using namespace std;

// // void printarr(vector<vector<int>> &arr) {
// //     for (vector<int> &row : arr) {
// //         for (int val : row) {
// //                 cout << val << ' ';
// //                 cout << "  "; // Print spaces for alignment
// //         }
// //         cout << '\n';
// //     }
// // }

// // int main() {
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);
// //     ifstream fin("lazy.in");
// //     ofstream fout("lazy.out");

// //     int n, k;
// //     fin >> n >> k;
// //     vector<vector<int>> ogarr(n, vector<int>(n, 0)); // Original array
// //     vector<vector<int>> arrnew(2 * n - 1, vector<int>(2 * n - 1, 0)); // Rotated array with pyramid shape

// //     // Read the input matrix
// //     for (int i = 0; i < n; i++) {
// //         for (int j = 0; j < n; j++) {
// //             fin >> ogarr[i][j];
// //         }
// //     }

// //     // Perform 45-degree rotation and align in pyramid format
// //     for (int i = 0; i < n; i++) {
// //         for (int j = 0; j < n; j++) {
// //             int diag = i + j;        // Determine diagonal index
// //             int center = n - 1;      // Center position in each row
// //             int pos = center - i + j; // Adjust position for pyramid alignment
// //             arrnew[diag][pos] = ogarr[i][j];
// //         }
// //     }

// //     // Print the rotated and aligned array
// //     printarr(arrnew);
// //     return 0;
// // }


#include<bits/stdc++.h>
using namespace std;

void printarr(vector<vector<int>> &arr){
    for(vector<int> i: arr){
        for(int j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("lazy.in");
    ofstream fout("lazy.out");

    int n, k;
    fin >> n >> k;
    vector<vector<int>> ogarr(n+1, vector<int>(n+1, 0));
    vector<vector<int>> arrnew(2*n+1, vector<int>(2*n+1, -1));

    for(int i=1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            fin >> ogarr[i][j];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int newX = i + j - 1;// -2 would be 0 indexed
            int newY = n - i + j;// lower you go with the same Y you get lefter, the change the Y axis to x = n so the new coordinates would be n - x + y, or use the coordinate transformation, or rotate the graph in your mind y = x is the new X axis
            arrnew[newX][newY] = ogarr[i][j];
        }
    }

    vector<vector<int>> pref(2*n+1, vector<int>(2*n+1, 0));

    // printarr(arrnew);

    for(int i = 1;i <= 2*n-1;i++){
        for(int j = 1;j <= 2*n-1;j++){
            int some = (arrnew[i][j] == -1)?0:arrnew[i][j];
            pref[i][j] = some + pref[i-1][j] + pref[i][j-1] -pref[i-1][j-1];
        }
    }

    // printarr(arrnew);

    long long ans = 0;
    // if this k wasn't given then it would have taken O(n^3) atleast
    for(int i = k+1;i <= 2*n-k-1;i++){
        for(int j = k+1;j <= 2*n-k-1;j++){
            if(pref[i][j] == -1) continue;
            long long curr_sum = 0;
            // curr_sum = pref[i+k+1][j+k+1] + pref[i-k][j-k] - pref[i+k+1][j-k] - pref[i-k][j+k+1];
            // ans = max(ans, curr_sum);

            int x1 = max(0, i - k);
            int y1 = max(0, j - k);
            int x2 = min(2*n-1, i + k);
            int y2 = min(2*n-1, j + k);

            curr_sum = pref[x2][y2];
            if(x1>0) curr_sum -= pref[x1-1][y2];
            if(y1>0) curr_sum -= pref[x2][y1-1];
            if(y1>0&&x1>0) curr_sum += pref[x1-1][y1-1];
            ans = max(ans, curr_sum);
        }
    }

    if(k >= n) ans = pref[2*n-1][2*n-1];

    fout << ans;

    return 0;
}