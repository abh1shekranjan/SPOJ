#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < n - k + 1; i++)
    {
        int max = 0;
        for (int j = i; j < i+k && j < n; j++)
        {
            if (array[j] > max)
            {
                max = array[j];
            }
            
        }
        cout << max << " ";
    }
    
}