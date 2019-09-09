#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string old;
string newWord;
int dp[3000][3000];
int min(int x,int y,int z){
    return min(min(x,y),z);
}
int editDistanceDP(int n1,int n2){

    for (int i = 0; i <=n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else if(old[i-1]==newWord[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
            }
            
        }
        
    }
    return dp[n1][n2];
    
    
}

int main(){
    int T;
    cin>>T;
   cin.ignore();
    while (T--)
    {
    	 
        cin>>old;
        cin>>newWord;
      //  cout<<old<<" "<<newWord<<endl;
        int answer=editDistanceDP(old.length(),newWord.length());
        cout<<answer<<endl;
       
    }
    
}