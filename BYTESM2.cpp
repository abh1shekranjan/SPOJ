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
        int** v = new int*[h];
		for(int i = 0; i < h; ++i)
		  v[i] = new int[w];
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int temp;
                cin>>temp;
                v[i][j]=temp;
            }
            
        }
        int** dp = new int*[h];
		for(int i = 0; i < h; ++i)
		  dp[i] = new int[w];
        for (int i = 0; i < w; i++)
        {
            dp[0][i]=v[0][i];
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
            answer=max(answer,dp[h-1][i]);
        }
        
        cout<<answer<<endl;
        

    }
    
}