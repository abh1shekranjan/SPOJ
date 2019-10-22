#include<iostream>
#include<string>
using namespace std;

long long modexpo(long long a,long long b,long long n)
{
    long long d=1;
    while(b)
    {
        if(b%2)
            d=(d*a)%n;
        b>>=1;
        a=(a*a)%n;
    }
    return d;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {	
        string s;
        long long int b;
        cin >> s;
        cin >> b;
        string w = "";
        w = s[s.length() - 1];
        long long int a = 0l;
        a = stoll(w, nullptr, 10);
        cout << modexpo(a, b, 10) << endl;
        cin.ignore();
    }
    
}