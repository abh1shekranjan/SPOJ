#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int budget, maxParty;
    cin >> budget;
    cin >> maxParty;
    while (budget != 0 && maxParty != 0)
    {
        int entranceFee[maxParty];
        int fun[maxParty];
        for (int i = 0; i < maxParty; i++)
        {
            cin >> entranceFee[i];
            cin >> fun[i];
        }
        int dp[maxParty][budget+1] = {};
        for (int i = 1; i <= budget; i++)
        {
            dp[0][i] = fun[0];
        }
        
        for (int i = 1; i < maxParty; i++)
        {
            for (int j = 1; j <= budget; j++)
            {
                if (j < entranceFee[i])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max((fun[i] + dp[i-1][j-entranceFee[i]]), dp[i-1][j]);
                }
            }
        }
        for (int i = 0; i < maxParty; i++)
        {
            for (int j = 0; j <= budget; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout<<endl;
        }
        
        
    }
    
}