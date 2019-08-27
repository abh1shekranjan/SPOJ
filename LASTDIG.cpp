#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	bool flag=true;
	int a,b;
	int t;
	cin>>t;
	while(t--){
		cin>>a;
		cin>>b;
		vector<int>lastDigit;
		if(a==0){
			cout<<0<<endl;
		}
		else{
			int counter=1;
			do{
				int num=pow(a,counter);
				if(lastDigit.empty()){
					lastDigit.push_back(num%10);
					counter++;
				}
				else{
					for(int i=0;i<lastDigit.size();i++){
						if(lastDigit[i]==(num%10)){
							flag=false;
							break;
						}
					}
					if(flag){
						lastDigit.push_back(num%10);
						counter++;
					}
				}
			}while(flag);
			int temp=b%(lastDigit.size());
			cout<<lastDigit[temp-1]<<endl;
		}
	}
}