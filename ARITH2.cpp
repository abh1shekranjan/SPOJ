#include <iostream>
#include <stack>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
    	cin.ignore();
        string s;
        getline(cin, s);
       // cout << s << " ";
        //cout << endl;
        string w = "";
        long long int answer = 0l;
        long long int temp = -1;
        bool isAdd, isSubtract, isMultiply, isDivide;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] != ' ')
            {
                w = w + s[i];
            }
            else if(s[i] == ' ')
            {
                if(w[0] < '0' || w[0] > '9'){
                    if(w[0] == '+')
                        isAdd = true;
                    else if(w[0] == '-')
                        isSubtract = true;
                    else if(w[0] == '*')
                        isMultiply = true;
                    else if(w[0] == '/')
                        isDivide = true;
                }
                else{
                    long long int a = stoll(w, nullptr, 10);
                   // cout << a << " ";
                    if(temp == -1){
                        temp = a;
                    }
                    else{
                        long long int b = temp;
                        if(isAdd)
                            temp = a + b;
                        else if(isDivide)
                            temp = b / a;
                        else if(isMultiply)
                            temp = a * b;
                        else if(isSubtract)
                            temp = a - b;
                    }
                    isAdd = isSubtract = isMultiply = isDivide = false;
                }
                w = "";
            }
            
        }
    cout << temp << endl;
    }
    
}