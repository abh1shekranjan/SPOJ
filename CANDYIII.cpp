#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
/**
This is solved suing the boost class
*/
int main(){
	long long t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		int128_t sum=0;
		for (int i = 0; i < n; ++i)
		{
			long long int temp;
			cin>>temp;
			sum=sum+temp;
		}
		if(sum%n==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}
}