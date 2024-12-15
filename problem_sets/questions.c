// #include<stdio.h>

// void swap(int *x, int *y){
//     int temp= *x;
//     *x=*y;
//     *y=temp;
// }

// int main(){
//     int i, n, j;
//     scanf("%d",&n);
//     int arr[n];
//     for(i=0;i<n;i++) scanf("%d",&arr[i]);
//     for(i=0;i<n;i++){
//         for(j=i;j<n;j++) if(arr[i]>arr[j]) swap(&arr[i],&arr[j]);
//         // Ascending, Reverse for descending
//     }
//     // for(i=0;i<n;i++) printf("%d\t",arr[i]);
//     int key;
//     scanf("%d",&key);
//     printf("%d", arr[n-key]);
//     return 0;
// }

#include<stdio.h>
#include<stdbool.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int uniq[n],i=0,j=0,c=0;
    bool flag=false;
    for(i=0;i<n;i++){
        flag=false;
        for(j=0;j<n;j++){// j=i otherwise &&
        if(arr[i]==arr[j]&&i!=j) flag=true;
        }
        if(!flag){
            uniq[c]=arr[i];
            c++;
        }
    }

    for(i=0;i<c;i++){
        printf("%d ",uniq[i]);
    }

    return 0;
}

// #include<stdio.h>

// int main(){
//     int n;
//     scanf("%d",&n);
//     int arr[n];
//     for(int i=0;i<n;i++) scanf("%d",&arr[i]);
//     int frequency[10000],i,j,c=0;// char
//     for(i=0;i<10000;i++) frequency[i]=0;
//     for(i=0;i<n;i++){
//         c=0;
//         for(j=0;j<n;j++){
//             if(arr[i]==arr[j]) c++;
//         }
//         frequency[arr[i]]=c;
//     }
//     for(i=0;i<10000;i++){
//         if(frequency[i]!=0) printf("%d occurs %d times\n",i,frequency[i]);
//     }
//     return 0;
// }

