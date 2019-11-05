#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        cin.ignore();
        string pattern;
        string haystack;
        cin >> pattern;
        cin >> haystack;
        int pLength = pattern.length();
        // To create an auxillary array for the pattern;
        int lpsPattern[pLength];
        memset(&lpsPattern, 0, pLength*sizeof(int));
        int i = 1;
        int m = 0;
        while (i < pLength)
        {
          if (pattern[i] == pattern[m])
          {
              m++;
              lpsPattern[i] = m;
              i++;
          }
          else if(pattern[i] != pattern[m] && m!=0)
          {
            m = lpsPattern[m-1];
          }
          else{
              lpsPattern[i] = 0;
              i++;
          }
          
        }
        int j = 0; // Counter For Haystack
        int k = 0; // Counter For Pattern
        bool flag = false;
        while (j < haystack.length())
        {
            if (haystack[j] != pattern[k])
            {
                if (k == 0)
                {
                    j++;
                }
                else{
                    k = lpsPattern[k-1];
                }
                
            }
            else{
                k++;
                j++;
                if (k == pLength) {
                    cout << (j - k) <<endl;
                    k = lpsPattern[k-1];
                    flag = true;
                }
            }
        }
       cout << endl; 
    }
}