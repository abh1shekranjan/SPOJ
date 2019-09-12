#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int h=0,w=0;


int main(){
    int T;
    cin>>T;

    while (T--)
    {
        cin>>h;
        cin>>w;
        vector<vector <int> >v(h,w);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int temp;
                cin>>temp;
                v[i][j]=temp;
            }
            
        }
        vector<vector<int> > dp(h,w);
        for (int i = 0; i < w; i++)
        {
            dp[0][i]=g[0][i];
        }
        for (int i = 1; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int a = -1,b = -1,c = -1;
                if(j>0)
                  a=dp[i-1][j-1];
                if(j<w-1)
                  b=dp[i-1][j+1];
                c=dp[i-1][j];
                dp[i][j]=max(max(a,b),c)+v[i][j];
            }
            
        }
        
        int answer=0;
        for (int i = 0; i < w; i++)
        {
            answer=max(answer,dp[n-1][i]);
        }
        
        
        

    }
    
}