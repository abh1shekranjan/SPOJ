//Someone Else's code
#include<iostream>
#include<algorithm>
using namespace std;

long long int func(long long int *dp, long long int n)
{
  	if(n==1 || n==0)
    		return n;
  	if(dp[n] != 0)
    		return dp[n];
  	dp[n] = max(n, func(dp,n/2) + func(dp, n/3) + func(dp, n/4));   
  	return dp[n];   
}

int main() 
{
  	long long int num;
  	while(cin >> num)
  	{
    		long long int *dp=new long long int[num+1];
    		cout << func(dp,num) << endl;
  	}
  	return 0;
}