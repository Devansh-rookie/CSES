#include<stdio.h>
#include <stdbool.h>
#include<math.h>


void count_words(){
    int i,c;
    char abc[100];
    gets(abc);
    for(i=0;abc[i]!='\0';i++){
        if(abc[i]==' ')c++;
    }
    printf("%d",c+1);
}

void compare(){
    char s1[100],s2[100];
    int i;
    bool flag=true;
    gets(s1);
    gets(s2);
    for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
        if(s1[i]!=s2[i]) flag= false;
    }
    if(!flag) printf("Not equal");
    else printf("Equal");
}

void count_all(){
    char s[100];
    int i;
    int frequency[256]={0};
    for(i=0;i<256;i++) frequency[i]=0;

    gets(s);
    
    for(i=0;s[i]!='\0';i++) frequency[s[i]]++;
    // store at s[i] which is the value at which is the ASCII Code
    for(i=0;i<256;i++) if(frequency[i]!=0) printf("%c has occurred %d times.\n",i,frequency[i]);
}

void sort_2powern(){
    int n,f;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++){
        for(int j=2;j<=arr[n];j++){
            while(arr[i]%i==0){
                arr[i]=arr[i]/j;
                f=i;
                if(f!=2) printf("%d ",arr[i]);
            }
        }
    }
}

int main(){

    // count_words();
    // compare();
    // count_all();
    // sort_2powern();
    return 0;
}
