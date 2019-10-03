#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int A,D;
    cin>>A;
    cin>>D;
    while(A!=0 && D!=0){
        int attacking[11]={0};
        int defending[11]={0};
        bool flag = false;
        for (int i = 0; i < A; i++)
        {
            cin>>attacking[i];
        }
        for (int i = 0; i < D; i++)
        {
            cin>>defending[i];
        }
        sort(defending,defending+D);
        for (int i = 0; i < A; i++)
        {
            if(attacking[i] < defending[1]){
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout<<'Y'<<endl;
        }
        else
        {
            cout<<'N'<<endl;
        } 
    }

}