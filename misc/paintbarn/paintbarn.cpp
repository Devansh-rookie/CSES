#include<bits/stdc++.h>
using namespace std;

int dimension = 1003;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");

    int n, k;

    fin >> n >> k;

    vector<vector<int>> arr(dimension, vector<int> (dimension, 0));
    for(int i = 1;i <= n;i++){
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        a++;b++;c++;d++;
        arr[a][b]++;
        arr[a][d]--;
        arr[c][d]++;
        arr[c][b]--;
    }
    long long ans = 0;
    // for(int i = 0;i < dimension;i++){
    //     for(int j = 0;j < dimension;j++){
    //         fout << arr[i][j] << ' ';
    //     }
    //     fout << endl;
    // }
    // fout <<endl;

    // make sure to not miss the 0's in the coordinates thats why the if statesments
    // or just increment the things in the starts
    for(int i=0; i < dimension;i++){
        for(int j = 0; j < dimension;j++){
            if(i>0) arr[i][j] += arr[i-1][j];
            if(j>0) arr[i][j] += arr[i][j-1];
            if(i>0 && j> 0) arr[i][j] -= arr[i-1][j-1];
            // arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            if(arr[i][j] == k) ans++;
        }
    }
    // for(int i = 0;i < dimension;i++){
    //     for(int j = 0;j < dimension;j++){
    //         fout << arr[i][j] << ' ';
    //     }
    //     fout << endl;
    // }
    fout << ans;

    return 0;
}