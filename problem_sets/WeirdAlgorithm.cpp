#include<iostream>
using namespace std;
long long int recursion(long long int n){
    if (n==1) return 1;
    else if(n>0 && n%2==0){
        cout<<n/2<<" ";
        return recursion(n/2);
    }
    else {
        cout<<3*n+1<<" ";
        return recursion(3*n+1);
    }
}

int main(){
    long long int n;
    cin>>n;
    cout << n<< " ";
    recursion(n);
    return 0;
}
