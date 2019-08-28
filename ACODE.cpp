#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str[5010];
    cin>>str;
    while(str[0]!='0')
    {
        int n=strlen(str);
        long long int dp[6000];
        for (int i = 0; i < n; i++)
        {
            dp[i]=0;
        }
        
        dp[0]=1;
        for(int i=1;i<strlen(str);i++){
            int two=(str[i-1]-'0')*10+(str[i]-'0');
            if(str[i]-'0')
                dp[i]=dp[i-1];
            if(two>9&&two<27){
                if(i==1)
                    dp[i]=dp[i]+1;
                else
                    dp[i]=dp[i]+dp[i-2];
                
            }   
        }
    cout<<dp[n-1]<<endl;        
    cin>>str;
    }
    if(str[0]=='0')
        return 0;
        
} 
    


