#include <iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=sqrt(n);i++) { 
		sum+=n/i - i + 1; 
	}
	cout<<sum;
}