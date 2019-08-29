#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
bool isPalindrome(string str){
    string copy=str;
    reverse(str.begin(),str.end());
    if(copy==str){
        return true;
    }
    return false;
}
int all_nine(string str)  //check if all digits are '9' 
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!='9')
            return 0;
    }
    return 1;
}
string getNextPalindrome(string s){
    int length=s.length();
    string left="";
    string right="";
    string answer="";
    char middle;
    bool flag=false;
    if(isPalindrome(s)){
        if(s.length()%2==0){
        left=s.substr(0,length/2);
        right=s.substr(length/2);
        left=left.substr(0,left.length()-1)+(char)(left[left.length()-1]+1);
        s=left+right;
        }
    }
    if(length%2==0){
        left=s.substr(0,length/2);
        cout<<left<<endl;
        right=s.substr(length/2);
        middle='x';
        flag=true;
        int countLeft=left.length();
        int countRight=0;
        while(flag){
            int leftNumber=left[countLeft-1]-'0';
            int rightNumber=right[countRight]-'0';
            if(leftNumber>rightNumber){
                flag=false;
                break;
            }
            else if(leftNumber==rightNumber){
                countLeft--;
                countRight++;
            }
            else{
                left=left.substr(0,countLeft-1)+(char)(left[countLeft-1]+1)+left.substr(countLeft);
                flag=false;
                break;
            }
        }
        string temp=left;
        reverse(left.begin(),left.end());
        answer=temp+left;
    }
    else{
        int mid=length/2;
        left=s.substr(0,mid);
        middle=s[mid];
        right=s.substr(mid+1);
        int leftNumber=left.back()-'0';
        int rightNumber=right[0]-'0';
        if(rightNumber>=leftNumber){
            if((middle-'0')==9){
                left=left.substr(0,left.length()-1)+(char)(left[left.length()-1]+1);
                string temp=left;
                reverse(left.begin(),left.end());
                answer=temp+'0'+left;
            }
            else{
                string temp=left;
                reverse(left.begin(),left.end());
                answer=temp+(char)(middle+1)+left;
            }
        }
        else{
                string temp=left;
                reverse(left.begin(),left.end());
                answer=temp+middle+left;
            }
    }
    cout<<left<<" "<<middle<<" "<<right<<endl;
    return answer;
}
string removeLeadingZeros(string s){
    while(s[0]=='0'){
        s=s.substr(1);
    }
    return s;
}
int main(){
    int t;
    string K;
    cin>>t;
    while(t--){
        cin>>K;
        int n=K.length();
        K=removeLeadingZeros(K);
        char ans[5000+3];
        if(all_nine(K))
        {                       //if all 9
            ans[0]='1';
            for(int i=0;i<n;i++)   
            {
                ans[i+1]='0';
            }
            ans[n]='1';
            ans[n+1]='\0';
            cout<<ans<<endl;
        }
 
        if(K.length()==1){
        	cout<<11<<endl;
        }
        else{
        	cout<<getNextPalindrome(K)<<endl;
        }
    }
}