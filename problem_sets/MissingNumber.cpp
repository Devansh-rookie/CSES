#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}

int main(){
    int n,j,i;
    cin>>n;
    int arr[n];
    for( i=0;i<n-1;i++) cin>>arr[i];
    for(i=0;i<n-1;i++){
        for(j=i;j<n-1;j++) if(arr[j]<arr[i]) swap(&arr[j],&arr[i]);
    }
    for (i=0;i<n-1;i++) if (arr[i]!=i+1){
        cout<<i+1;
        break;
    }
    return 0;
}