#include <iostream>
using namespace std;

int main() {
	string s;
	cin>>s;
	if(s[s.length()-1]=='0'){
		cout<<2<<endl;
	}
	else{
		cout<<1<<endl;
		cout<<s[s.length()-1]<<endl;
	}
		
	
	
	return 0;
}