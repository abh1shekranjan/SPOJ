#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    while (n!=0)
    {
        vector<int> givenList(n);
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            givenList[i]=temp;
        }
        bool flag=true;
        int position=0;
        for(int i=1;i<=n;i++){
            for (int j = 0; j < n; j++)
            {
                if(givenList[j]==i){
                    position=j+1;
                    break;
                }
            }
            if(position!=givenList[i-1]){
                flag=false;
                break;
            }
            else{
                flag=true;
            }
            
        }
        if(flag==true){
            cout<<"ambiguous"<<endl;
        }
        else{
            cout<<"not ambiguous"<<endl;
        }

        cin>>n;
    }
    
}