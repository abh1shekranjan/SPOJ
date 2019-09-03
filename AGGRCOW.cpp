#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int N,C;
int func(int num,int array[]){
    int cows=1,pos=array[0];
    for(int i=1;i<N;i++){
        if(array[i]-pos>=num){
            pos=array[i];
            cows++;
            if(cows==C)
            return 1;
        }
    }
    return 0;
}


int binSearch(int array[]){
int left=0,right=array[N-1],max=-1;

while(right>left){
    int mid=(left+right)/2;
    if(func(mid,array)==1){
        if(mid>max){
            max=mid;
        }
        left=mid+1;
    }
    else{
        right=mid;
    }
}
return max;
}


int main(){
int t;
cin>>t;
while(t--){
    cin>>N;
    cin>>C;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    sort(arr,arr+N);
    int ans=binSearch(arr);
    cout<<ans<<endl;
}
}