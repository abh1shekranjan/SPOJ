#include<iostream>
using namespace std;
int RevNumber(int n){
    int m=0;
    while(n>0){
        m=m*10+(n%10);
        n=n/10;
    }
    return m;
}
int RemoveZeros(int n){
    while(n%10==0){
        n=n/10;
    }
    return n;
}
int main(){
    int N;
    cin>>N;
    int num1,num2;
    while(N--){
    cin>>num1;
    cin>>num2;
    int numberZerosRemoved=RemoveZeros(num1);
    int numberZerosRemoved2=RemoveZeros(num2);
    int numberReversed=RevNumber(numberZerosRemoved);
    int numberReversed2=RevNumber(numberZerosRemoved2);
    int sum=numberReversed+numberReversed2;
    int sumZerosRemoved=RemoveZeros(sum);
    int sumReversed=RevNumber(sumZerosRemoved);
    cout<<sumReversed<<endl;
    }
    return 0;
}