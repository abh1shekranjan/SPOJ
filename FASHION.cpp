#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,N;
    cin>>t;
    while (t--)
    {
        cin>>N;
        vector<int>x(N);
        vector<int>y(N);
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin>>temp;
            x.push_back(temp);
        }
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin>>temp;
            y.push_back(temp);
        }
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        int answer=0;
        for (int i = 0; i < N; i++)
        {
            answer=answer+(x[i]*y[i]);
        }
        cout<<answer<<endl;
    }
    
}