#include<iostream>
#include<queue>
#define MAX 2019
using namespace std;

int V;

bool isBipartiteUtil(int G[][MAX],int colorArr[],int src){
    colorArr[src] = 1;
    queue <int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (G[u][u] == 1)
        {
            /* self loop */
            return false;
        }

        for (int i = 0; i < V; i++)
        {
            if(G[u][i] && colorArr[i] == -1)
            {
              colorArr[i] = 1 - colorArr[u];
              q.push(i);
            }

            else if (G[u][i] && colorArr[i] == colorArr[u])
            {
                /* already colored hence graph cannot be bipartite */
                return false;
            }
            
        }
        
        
    }
    return true;
}

bool isBipartite(int G[][MAX]){
    int colorArr[V];
    for (int i = 0; i < V; i++)
    {
        colorArr[i]=-1;
    }

    for (int i = 0; i < V; i++)
    {
        if (colorArr[i] == -1)
        {
            if (isBipartiteUtil(G,colorArr,i) == false)
            {
                return false;
            }
            
        }
        
    }
    return true;
    
}



int main(){
    int t;
    cin>>t;
    int count=1;
    while (t--)
    {
        int edges;
        cin>>V;
        cin>>edges;
        int G[MAX][MAX]={0,0};
        
        for (int i = 0; i < edges; i++)
        {
            int temp1;
            int temp2;
            cin>>temp1;
            cin>>temp2;
            G[temp1-1][temp2-1]=1;
            G[temp2-1][temp1-1]=1;
        }
        cout<<"Scenario #"<<count++<<":"<<endl;
        if (isBipartite(G)==false)
        {
            cout<<"Suspicious bugs found!"<<endl;
        }
        else
        {
            cout<<"No suspicious bugs found!"<<endl;
        }
        
    }
    
}