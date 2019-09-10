#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        unsigned long long _3term,_3lastterm,sum;
        cin>>_3term;
        cin>>_3lastterm;
        cin>>sum;
        unsigned long long n;
        n=(2*sum)/(_3term+_3lastterm);
        //cout<<n<<" ";
        unsigned long long d=(_3lastterm-_3term)/(n-5);
        //cout<<d<<" ";
        unsigned long long a=_3term-(2*d);
       // cout<<a<<" ";
        for (auto i = 0; i < n; i++)
        {
            cout<<a+(i*d)<<" ";
        }
        cout<<endl;
        
    }
    
}