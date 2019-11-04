#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int profit[2000];
int cache[2000+1][2000+1];

int calculateMaxTreat(int begin, int end) {
    if (begin > end){
        return 0;
    }
    int year = N - (end - begin);
   
    if (begin == end){
    	return year*profit[begin];
    }
    if(cache[begin][end] != -1){
        return cache[begin][end];
    }
   
    return cache[begin][end] = max( year * profit[begin] + calculateMaxTreat(begin+1, end)  , (year * profit[end] + calculateMaxTreat(begin, end-1) ));
}
int main(){
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> profit[i];
    }
    memset(&cache, -1, 2001*2001*sizeof(int));
    int answer = calculateMaxTreat(0, N-1);
    cout << answer << endl;
    
}
