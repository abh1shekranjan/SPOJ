#include <iostream>
using namespace std;

int main()
{
	int n;
	string s;
	do{
		cin>>n;
		if(n!=0){
			cin>>s;
			int l=s.length();
			int rows=l/n;
			char encode[rows][n];
			int count=0;
			for(int i=0;i<rows;i++){
				for(int j=0;j<n;j++){
					if(i%2==0){
						encode[i][j]=s.at(count++);
					}
					else{
						encode[i][n-j-1]=s.at(count++);
					}
				}
			}
			string answer="";
			for(int i=0;i<n;i++){
				for(int j=0;j<rows;j++){
					answer=answer+encode[j][i];
					
				}
			}
			cout<<answer<<endl;
		}
	}while(n!=0);
	return 0;
}