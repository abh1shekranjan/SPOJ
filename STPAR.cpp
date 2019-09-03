#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        vector<int>loveMobile;
        stack<int>s;
        vector<int>final;
        bool used=false;
        for (int i = 0; i < T; i++)
        {
            int temp;
            cin>>temp;
            loveMobile.push_back(temp);
        }
        for(int i=0;i<T;i++){
            int temp=loveMobile[i];
          // cout<<"Temp1: "<<temp<<" "<<endl;
            if(!s.empty()&&temp>s.top()){
                while(!s.empty()&&temp>s.top()){
                    final.push_back(s.top());
                  // cout<<"Stack Top: "<<s.top()<<" "<<endl;
                    s.pop();
                }
            }
            // if(temp>loveMobile[i+1]){
            //     s.push(temp);
            //     used=true;
            //    // cout<<"Temp2: "<<temp<<" "<<endl;
            // }
            // else{
            // //	cout<<"Final array: "<<temp;
            //     final.push_back(temp);
            // }
            s.push(temp);

        }
            while (!s.empty())
            {
                final.push_back(s.top());
                s.pop();
            }
            
    
        bool flag1=is_sorted(final.begin(),final.end());
       // bool flag2=is_sorted(final.rbegin(),final.rend());
        	if(flag1){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        cin>>T;
        }
        
        
    }
