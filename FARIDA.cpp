#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int  max(long long int a,long long int b){
	return a>b?a:b;
}
long long int maxGold(long long int *mGold,int n){
    if (n == 0)
        return 0;
    if (n == 1)
        return mGold[0];
    if (n==2)
        return max(mGold[0],mGold[1]);
    long long int dp[n+9]={0};
    dp[0]=mGold[0];
    dp[1]=max(mGold[0],mGold[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i]=max(mGold[i]+dp[i-2],mGold[i-1]);
    }
    long long int max=0;
    for(int i=0;i<=n;i++){
    	if(max<dp[i]){
    		max=dp[i];
    	}
    }
    return max;
    
    
}

int main(){
    int t,N;
    cin>>t;
    int count=1;
    while (t--)
    {

        cin>>N;
        if(N==0){
        	cout<<"Case 1: 0"<<endl;
        }
        else{
        	 long long int monsterGold[10009]={0};
        for (int i = 0; i < N; i++)
        {
            long long int temp;
            cin>>temp;
            monsterGold[i]=temp;
        }
        long long int answer=maxGold(monsterGold,N);
        cout<<"Case "<<count++<<": "<<answer<<endl;
        }
    }
    
}