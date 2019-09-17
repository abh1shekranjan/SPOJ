#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[6101][6101]={0};
string s;
string w="";

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while (t--)
    {
        cin>>s;
        for (int i = 0; i < s.length(); i++)
            w=s[i]+w;
        //cout<<s<<" "<<w<<endl;
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i]=1;
        }
        
        for (int i = 2; i <= s.length(); i++)
        {
            for (int j = 0; j < s.length()-i+1; j++)
            {
                int k=j+i-1;
                if(s[k]==s[j]&&i==2)
                    dp[j][k]=2;
                else if(s[k]==s[j])
                    dp[j][k]=dp[j+1][k-1]+2;
                else
                    dp[j][k]=max(dp[j][k-1],dp[j+1][k]);
            }
            
        }
       /* for(int i=0;i<s.length();i++){
        	for(int j=0;j<s.length();j++){
        		cout<<dp[i][j]<<" ";
        	}
        	cout<<endl;
        }*/
        cout<<s.length()-dp[0][s.length()-1]<<endl; 
    }
    
}