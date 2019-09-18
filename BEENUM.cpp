#include <bits/stdc++.h>
using namespace std;
int main() {
   int n;
   scanf("%d",&n);
   while(n!=-1)
   {
      if((n-1)%6==0)
      {
         int i;
         for(i=0; i<=n/6; ++i)
            if(((3*i*(i+1))+1) == n)
            {
               printf("Y\n");
               break;
            }
         if(i == n/6 +1)   
            printf("N\n");
      }
      else
         printf("N\n");
      scanf("%d",&n);   
   }
   return 0;
}