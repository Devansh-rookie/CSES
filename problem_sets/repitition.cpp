#include<iostream>
#include<string>
using namespace  std;
int main(){
    long long streak=0,temp=0;
    string str;
    cin>>str;// otherwise getline() function is to be used

    for(long long i=0;i<str.size()-1;i++){
        for(long long j=i;j<str.size();j++){
            if(str[i]==str[j]){
                    temp++;
                    streak=max(temp,streak);
                }
            else{
                    temp=0;
                    break;
                }
        }
    }
    cout<<streak<<endl;
    return 0;
}

long long max(long long a,long long b){
    long long maxi=INT16_MIN;
    if(a>b) maxi=a;
    else maxi= b;
    return maxi;
}