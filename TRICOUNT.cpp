#include<iostream>
using namespace std;

int main(){
    int T;
    unsigned long long N,sum;
    cin>>T;
    while (T--)
    {
        cin>>N;
        if(N%2==0)
        sum=(N*(N+2)*((2*N)+1))/8;
        else
        sum=((N*(N+2)*((2*N)+1))-1)/8;
        cout<<sum<<endl;
    }
    
}