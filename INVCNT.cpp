#include<iostream>
using namespace std;

long long int merge(int arr[], int temp[], int left, 
          int mid, int right) 
{ 
    int i, j, k; 
    long long int inv_count = 0; 
  
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 

    while (j <= right) 
        temp[k++] = arr[j++]; 

    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
}

long long int newmergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid;
    long long int inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count = newmergeSort(arr, temp, left, mid); 
        inv_count += newmergeSort(arr, temp, mid + 1, right); 
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
long long int mergeSort(int arr[], int array_size) 
{ 
    int temp[array_size]; 
    return newmergeSort(arr, temp, 0, array_size - 1); 
} 


int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
           // cout<<i<<": "<<arr[i]<<" ";
        }
        //cout<<endl;
       long long  int answer=mergeSort(arr,n);
        cout<<answer<<endl;
    }
    
}