#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    for (int i = 1; i <= T; i++)
    {
        int amount,size;
        vector <int> stamps;
        cin>>amount;
        cin>>size;
        int sum=0;
        for (int i = 0; i < size; i++)
        {
            int temp;
            cin>>temp;
            stamps.push_back(temp);
            sum=sum+temp;
        }
        if(amount>sum){
            cout<<"Scenario #"<<i<<":"<<endl;
            cout<<"impossible"<<endl;
        }
        else if(amount==sum){
            cout<<"Scenario #"<<i<<":"<<endl;
            cout<<size<<endl;
        }
        else{
            sort(stamps.begin(),stamps.end(),greater<int>());
            sum=0;
            int pos=0;
            for(int j=0;j<size;j++){
                if(sum>=amount){
                	pos=j;
                    break;
                }
                else{
                    sum=sum+stamps[j];
                    
                }
            }
            cout<<"Scenario #"<<i<<":"<<endl;
            cout<<pos<<endl;
        }
        
    }
    
}