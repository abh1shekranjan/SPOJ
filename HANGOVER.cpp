#include<iostream>
using namespace std;
int main(){
    double t=0.00d;
    cin>>t;
    while(t!=0.00){
        int n=1;
        double sum=0.00d;
        while(sum<t){
            sum=sum+(1.00/(n+1.00));
            n=n+1;
        }
        cout<<n-1<<" card(s)"<<endl;
        cin>>t;
    }
}