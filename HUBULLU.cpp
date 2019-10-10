#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        long long N;
        int a;
        cin >> N;
        cin >> a;
        if(a == 0){
            cout << "Airborne wins." << endl;
        }
        else{
            cout << "Pagfloyd wins." << endl;
        }
    }
    
    
}