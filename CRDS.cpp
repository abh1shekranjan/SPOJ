#include<iostream>

using namespace std;

int main(){

    int T;
    cin>>T;
    long long int N;
    while (T--)
    {
        cin>>N;
        long long int answer=3*((N*(N+1))/2)-N;    
        cout<<answer%1000007<<endl;
    }
    
}