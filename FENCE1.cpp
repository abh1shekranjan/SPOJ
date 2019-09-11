#include <iostream>
#include<iomanip>
#define pi 3.1415926536
using namespace std;

int main(){
    int L;
    cin>>L;
    while (L!=0)
    {
        double ans=(L*L)/(2*pi);
        cout<<fixed<<setprecision(2)<<ans<<endl;
        cin>>L;
    }
    
}