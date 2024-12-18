#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1){
        cout << "1"<<endl;
        return 0;
    }
    if(n <= 3){
        cout <<"NO SOLUTION"<<endl;
        return 0;
    }
    // print all odd then all even numbers
    // as odd numbers and even number have the difference of 2 and never 1 so we just check if the difference between the last odd and the first even has a difference more than 1 or not
    // for 4 start from n and subtract till 0

    if(n == 4){
        cout << "2 4 1 3"<< endl;
        return 0;
    }
    for(int i=1;i <= n;i+=2){
        cout << i << " ";
    }
    for(int i = 2;i <= n;i+=2){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}