#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
    int T, N, K;
    cin >> T;
    while (T--)
    {
        cin >> N;
        cin >> K;
        int heights[N];
        for (auto i = 0; i < N; i++)
        {
            cin >> heights[i];
        }
        sort(heights, heights+N);
        int min = INT_MAX;
        for (int i = 0; i <= N - K; i++)
        {
            if((heights[i+K-1] - heights[i]) < min){
                min = heights[i+K-1] - heights[i];
            }
        }
        cout << min << endl; 
    }
    
}