#include<iostream>
#include<string>

using namespace std;

string multiplyByTwo(string n){
    int l=n.length();
    string w="";
    int carry=0;
    for (int i = l-1; i >=0; i--)
    {
        int digit=n[i]-'0';
        if(digit<5){
            digit=2*digit+carry;
            carry=0;
            if(digit>=10){
                carry=digit/10;
                w=to_string((digit%10))+w;
            }
            else{
                w=to_string(digit)+w;
            }
        }
        else{
            digit=2*digit+carry;
            carry=digit/10;
            w=to_string((digit%10))+w;
        }
    }
    if(carry>0){
    	w=to_string(carry)+w;
    }
    return w;
}


string subtractByOne(string n){
    int l=n.length();
    int carry=0;
    string w="";
    if (n[l-1]!='0')
        {
            int digit=n[l-1]-'0';
            digit--;
            w=to_string(digit)+w;
            w=n.substr(0,l-1)+w;
            return w;
        }
        else
        {
            int i=l-1;
            while(n[i]=='0'){
                w='9'+w;
                i--;
            }
            if(i==0&&n[0]=='1'){
                return w;
            }
            else{
                int digit=n[i]-'0';
                digit--;
                 w=to_string(digit)+w;
                 w=n.substr(0,i)+w;
                 return w;
            }
            

        }
        
        
    }
    


int main(){
    string s;
    while (cin>>s)
    {
     if((s.length()==1&&s[0]=='1')||(s.length()==1&&s[0]=='0')){
     	if(s[0]=='1'){
     		cout<<1<<endl;	
     	}
     	else if(s[0]=='0'){
     		cout<<0<<endl;
     	}
     	
     }
     else if(s[0]=='-'){
     	cout<<0<<endl;
     }
     else{
     string w=subtractByOne(s);
     cout<<multiplyByTwo(w)<<endl;
    }
    }
}