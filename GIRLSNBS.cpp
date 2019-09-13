#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int G,B;
    cin>>G;
    cin>>B;
    while (G!=-1&&B!=-1)
    {
        int answer=(int)(G+B)/(min(G,B)+1);
        cout<<answer<<endl;
        cin>>G;
        cin>>B;
    }
    
}