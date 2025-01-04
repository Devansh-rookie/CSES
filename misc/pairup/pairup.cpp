#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    long long n;
    fin >> n;
    map<long long , long long> m;
    for(int i = 0;i < n;i++){
        long long freq, out;
        fin >> freq >> out;
        m[out] += freq;
    }

    map<long long, long long>::iterator left = m.begin();
    map<long long, long long>::iterator right = m.end();

    right--;

    long long ans = 0;

    while(left != m.end() && right != m.end() && right->first >= left->first){
        if(right -> second > left -> second){
            right -> second -= left->second;
            left->second = 0;
        }
        else{
            left->second -= right->second;
            right->second = 0;
        }

        // long long minn = min(left->second, right->second);

        ans = max(ans, right->first + left->first);

        // right -> second -= minn;
        // left->second -= minn;

        if(!(left->second)){
            left++;
        }
        if((!(right->second))&& left != right){
            right--;
        }
        if (left == right && left->second == 0) break;
    }

    fout << ans << endl;
    return 0;
}