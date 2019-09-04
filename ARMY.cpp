#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    string blank;
    cin>>t;
    while (t--)
    {
        int NG,NM;
        cin>>NG;
        cin>>NM;
        vector<int> armyG;
        vector<int> armyM;
        for (int i = 0; i < NG; ++i)
        {
            int temp;
            cin>>temp;
            armyG.push_back(temp);
        }
        for (int i = 0; i < NM; ++i)
        {
            int temp;
            cin>>temp;
            armyM.push_back(temp);
        }
        sort(armyG.begin(),armyG.end());
        sort(armyM.begin(),armyM.end());
        if(armyM.back()<=armyG.back()){
            cout<<"Godzilla"<<endl;
        }
        else{
            cout<<"MechaGodzilla"<<endl;
        }
    }
    
}