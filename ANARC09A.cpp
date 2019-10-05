#include <iostream>
#include <stack>
using namespace std;
int main() {
    int k=1;
    string s;
    cin>>s;
    while (s[0] != '-') {
        string w = "";
        stack <char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{') {
                st.push('{');
            }
            if (s[i] == '}')
            {
                if(!st.empty()){
                    st.pop();
                }
                else
                {
                    w = w + '}';
                }
            } 
        }
        while (!st.empty()) {
            w = w + st.top();
            st.pop();
        }
        int n=0;
        for (int i = 0; i < w.length(); i++) {
        	if(w[i] == '{')
        		n++;
        }
        cout<<k++<<". "<<(w.length()/2 + n%2)<<endl;
        //cout<<w<<" "<<endl; 
        cin>>s;
    }
}