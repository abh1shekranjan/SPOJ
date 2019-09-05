#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while (t--)
    {
    	cin.ignore();
        string s;
        getline(cin,s);
        int posPlus=s.find("+");
        int posMachula=s.find("m");
        int posEquals=s.find("=");
       // cout<<t<<": "<<s<<endl;
       // cout<<posPlus<<" "<<posMachula<<" "<<posEquals<<endl;;
        string w="";
        int arr[5];
        int count=0;
        s=s+" ";
        if(posMachula>posEquals){
            for(int i=0;i<posPlus;i++){
                if(s[i]==' '){
                    int x=stoi(w);
                    w="";
                    arr[count++]=x;
                }
                else{
                    w=w+s[i];
                }
            }
            w="";
            for(int i=(posPlus+2);i<posEquals;i++){
                if(s[i]==' '){
                    int x=stoi(w);
                    w="";
                    arr[count++]=x;
                }
                else{
                    w=w+s[i];
                }
            }
            cout<<s.substr(0,posEquals+1) <<" "<<arr[1]+arr[0]<<endl;
        }
        else{
            if (posMachula<posPlus)
            {
                for(int i=(posPlus+2);i<posEquals;i++){
                    if(s[i]==' '){
                        int x=stoi(w);
                        w="";
                        arr[count++]=x;
                    }
                    else{
                        w=w+s[i];
                    }
                }
                for(int i=(posEquals+2);i<s.length();i++){
                    if(s[i]==' '){
                        int x=stoi(w);
                        w="";
                        arr[count++]=x;
                    }
                    else{
                        w=w+s[i];
                    }
                }
              cout<<arr[1]-arr[0]<<" "<<s.substr(posPlus)<<endl;
            }
            else{
                for(int i=0;i<posPlus;i++){
                    if(s[i]==' '){
                        int x=stoi(w);
                        w="";
                        arr[count++]=x;
                    }
                    else{
                        w=w+s[i];
                    }
                }
                for(int i=(posEquals+2);i<s.length();i++){
                    if(s[i]==' '){
                        int x=stoi(w);
                        w="";
                        arr[count++]=x;
                    }
                    else{
                        w=w+s[i];
                    }
                }
                cout<<s.substr(0,posPlus+1)<<" "<<arr[1]-arr[0]<<" "<<s.substr(posEquals)<<endl;
            }
            
        }
    }
    
}