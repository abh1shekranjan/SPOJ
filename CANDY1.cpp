#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=0;
    
    do{
        cin>>n;
        if(n!=-1){
            vector<int>arr;
            int sum=0;
            for (int i = 0; i < n; i++){
               int temp;
               cin>>temp;
               sum=sum+temp;
               arr.push_back(temp);
            }
            if(sum%n==0){
                int avg=sum/n;
                int answer=0;
                for(int j=0;j<n;j++){
                    if(arr[j]<avg){
                        answer=answer+(avg-arr[j]);
                    }
                }
                cout<<answer<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }while(n!=-1);
}