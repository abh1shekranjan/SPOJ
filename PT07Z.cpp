#include<iostream>
#include<vector>
using namespace std;

bool checkMax[100009]={false};
int total=0;

int dfs(vector<int> v[],int n){
    int m,m1=-1,m2=-1;
    checkMax[n]=1;
    for(int i=0;i<v[n].size();i++){
        if(!checkMax[v[n][i]]){
            m=dfs(v,v[n][i]);
            if(m>=m1){
                m2=m1;
                m1=m;
            }
            else if(m>m2){
                m2=m;
            }
        }

    }
    total=max(total, m1+m2+2);
    return (m1+1);
}

int main(){
    int n,a,b;
    cin>>n;
    vector<int> v[n+9];
    for (int i = 0; i < n-1; i++)
    {
        cin>>a;
        cin>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(v,1);
    cout<<total<<endl;
    
}