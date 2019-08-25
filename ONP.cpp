#include<iostream>
#include<string>
#include<stack>
using namespace std;
int precedence(char c){
    switch (c)
    {
    case '^':
        return 3;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    default:
        return -1;
        break;
    }
}

string InfixToPostfix(string s){
    int l=s.length();
    string answer="";
    stack <char> stackOperator;
    stackOperator.push('N');
    for (int i = 0; i < l; i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            answer=answer+s[i];
        }
        else if(s[i]=='('){
            stackOperator.push(s[i]);
        }
        else if(s[i]==')'){
            while(stackOperator.top()!='N'&&stackOperator.top()!='('){
                char c=stackOperator.top();
                stackOperator.pop();
                answer=answer+c;
            }
            if(stackOperator.top()=='('){
                stackOperator.pop();
            }
        }
        else{
            if(precedence(s[i])>precedence(stackOperator.top())||stackOperator.top()=='N'){
                stackOperator.push(s[i]);
            }
            else{
                while(precedence(stackOperator.top())>=precedence(s[i])){
                    char c=stackOperator.top();
                    stackOperator.pop();
                    answer=answer+c;
                }
                stackOperator.push(s[i]);

            }

        }

    }
    while(stackOperator.top()!='N'){
                char c=stackOperator.top();
                stackOperator.pop();
                answer=answer+c;
}
return answer;
}

int main(){
    int t;
    string n;
    string answer;
    cin>>t;
    while (t--)
    {
        cin>>n;
        answer=InfixToPostfix(n);
        cout<<answer<<endl;
    }
    
}