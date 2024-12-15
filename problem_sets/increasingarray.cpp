#include<iostream>
using namespace std;
int main(){
    long long count=0;
    long long n;
    cin>>n;
    int arr[n];
    for(long long i=0;i<n;i++) cin>>arr[i];
    for(long long i=1;i<n;i++){
        while(arr[i]<=arr[i-1]){
            arr[i]++;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}