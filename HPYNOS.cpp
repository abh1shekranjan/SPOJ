#include<iostream>
#include<stdio.h>
using namespace std;
long long sumOfSquares(long long n){
    long long answer=0;
    while (n>0)
    {
        long long d=n%10;
        answer=answer+d*d;
        n=n/10;
    }
    return answer;
}

int main(){
    long long N;
    cin>>N;
    long long prev=N;
    long long current=N;
    long long count=0;
    bool flag=false;
    do{
        prev=current;
        current=sumOfSquares(prev);
        count++;
        if (current==1)
        {
            cout<<count<<endl;
            flag=true;
            break;
        }
        if (current==4||current==16||current==37||current==58||current==89||current==145||current==42||current==20)
        {
            cout<<"-1"<<endl;
            flag=false;
            break;
        }
        
        
    }while(prev!=current||current!=1);
}