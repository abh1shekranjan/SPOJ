#include<iostream>
using namespace std;
int main(){
    int x1,x2,x3;
    bool flag=false;;
    do{
        cin>>x1;
        cin>>x2;
        cin>>x3;
        flag=false;
        if(x1==0){
            if(x2==0){
                if(x3==0){
                    flag=true;
                }
            }
        }
        if(flag){
        }
        else{
            if(x1==x2==x3){
                cout<<"GP "<<(x3*(x2/x1))<<endl;
            }
            if((x2-x1)==(x3-x2)){
                cout<<"AP "<<(x3+(x2-x1))<<endl;
            }
            else
            {

                cout<<"GP "<<(x3*(x2/x1))<<endl;
            }
        }
        
    }while(!flag);
}