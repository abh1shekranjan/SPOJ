#include<iostream>
#include<math.h>

using namespace std;

int phi(int n) 
{ 
    int result = n; 
    for (int p = 2; p * p <= n; ++p) {  
        if (n % p == 0) { 

            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    } 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 


int main(){
	int T;
	cin>>T;
	while (T--)
	{
		int n; 
		cin>>n;
		int answer=phi(n);
		cout<<answer<<endl;
	}
	
}