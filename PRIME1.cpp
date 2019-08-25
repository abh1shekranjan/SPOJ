#include<stdio.h>
#include<iostream>

using namespace std;
int main(){
    int t,x;
    long int m,n;
    cin>>t;
    while(t--){
        cin>>m;
        cin>>n;
        for (int i = m; i <=n; ++i)
        {
            x=1;
            if(i==1){x=0;}
            else if(i==2||i==3){x=1;}
            else{
                for(int j=2;j<=sqrt(i);j++)
                {
                    if(i%j==0){x=0;break;}
                }
            }
            if(x==1){cout<<i<<endl;}
        }
        cout<<endl;
    }
    return 0;
}