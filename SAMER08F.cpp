#include<iostream>
using namespace std;
int main(){
    int n;
    do{
        
        long long answer=0;
        cin>>n;
        if(n!=0){
            answer=(n*(n+1)*((2*n)+1))/6;
            cout<<answer<<endl;
        }
    }while(n!=0);
}