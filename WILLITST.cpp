#include<iostream>
#include<math.h>
using namespace std;
bool isPower(long int n){
    if (n==0) return false;
    else
    return (ceil(log2(n))==floor(log2(n)));
}
int main(){
    long int n;
    cin>>n;
    if(isPower(n))
    cout<<"TAK"<<endl;
    else
    cout<<"NIE"<<endl;
    
}