#include<stdio.h>
using namespace std;
int main(){
    long long N;
    scanf("%lld",&N);
    long long result=0;
    for (long long i = 0; i < N; i++)
    {
        long long temp;
        scanf("%lld",&temp);
        result=result^temp;
    }
    printf("%lld\n",result);
    return 0;
}