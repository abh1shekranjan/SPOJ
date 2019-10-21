#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N;
    cin >> M;
    vector<int> hotelValues(N,0);
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        hotelValues[i] = temp;
    }
    int currentSum = 0;
    int left = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < N; ++i) {
        currentSum += hotelValues[i];
        if(currentSum == M){
            break;
        }
        while (currentSum > M){

            currentSum -= hotelValues[left];
            left++;
        }
        maxSum = max(maxSum, currentSum);
    }
    cout << maxSum << endl;
}