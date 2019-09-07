#include<iostream>
using namespace std;

int main(){
    int t,N;
    cin>>t;
    while (t--)
    {
        int count=1;
        int i=1,j=1;
        cin>>N;
        while(count<N){
            if(i==1){
                j++;
                count++;
            }
            if (count==N)
                break;

            
            while(j!=1&&count!=N){
                i++;
                j--;
                count++;
            }

            if (count==N)
                break;

            if(j==1){
                i++;
                count++;
            }
            if (count==N)
                break;
            while (i!=1&&count!=N)
            {
                i--;
                j++;
                count++;
            }
        }
        cout<<"TERM "<<N<<" IS  "<<i<<"/"<<j<<endl;
    }
    
}