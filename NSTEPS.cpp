#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int t;
    int x,y;
    cin>>t;
    while (t--)
    {
        /* code */
        cin>>x;
        cin>>y;
        if ((x==y)||(x==(y+2)))
        {
            if(y%2==0){
                cout<<x+y<<endl;
            }
            else{
                cout<<(x+y-1)<<endl;
            }
        }
        else{
            cout<<"No Number"<<endl;
        }
        
    }
    
}