#include<stdio.h>
#include<string.h>

int min(int a,int b){
    if(a>b) return b;
    else return a;
}


int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int main(){
    char a[100],b[100];
    gets(a);
    gets(b);
    char c[100], d[100], e[100];
    int i,l1,l2,j;
    for(i=0;a[i]!='\0';i++);
    l1=i;
    for(i=0;b[i]!='\0';i++);
    l2=i;
    int maxi= max(l1,l2);
    for(i=0;i<maxi;i++){
        if(a[i]==b[i]) c[i]= a[i];
    }
    puts(c);
    i=0;
    while(i<maxi){
        if(c[i]!=b[i]) printf("%c",b[i]);
        i++;
    }
    printf("\n");
    i=0;
    while(i<maxi){
        if(c[i]!=a[i]) printf("%c",a[i]);
        i++;
    }
    return 0;    
}
