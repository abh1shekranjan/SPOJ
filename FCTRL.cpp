#include <iostream>
using namespace std;
int FindTrailingZeros(int n){
    int count=0;
    for (int i = 5; n/i >= 1; i+=5){
        count += n/i;
    }
    return count;
    
}
int main(){
    int T,N;
    cin>>T;
    while(T--){
        cin>>N;
        int answer=FindTrailingZeros(N);
        cout<<answer<<endl;
    }
    return 0;

}