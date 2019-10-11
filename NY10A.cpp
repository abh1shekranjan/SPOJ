#include <iostream>

using namespace std;

int main(){
    int P;
    cin >> P;
    while(P--) {
        int N;
        string s;
        cin >> N;   
        cin >> s;
        int arr[8] = {0};
        int length = s.length();
        for (int i = 0; i < length; i++)
        {
            if(length >= 3){
                if(i+3 <= length){
                    string patternCheck = "";
                    if(i+3 == length){
                        patternCheck = s.substr(i);
                    }
                    else{
                        patternCheck = s.substr(i,3);
                    }
                    //cout << patternCheck << " ";
                    if (patternCheck == "TTT")
                    {
                        arr[0]++;
                    }
                    else if (patternCheck == "TTH")
                    {
                        arr[1]++;
                    }
                    else if (patternCheck == "THT")
                    {
                        arr[2]++;
                    }
                    else if (patternCheck == "THH")
                    {
                        arr[3]++;
                    }
                    else if (patternCheck == "HTT")
                    {
                        arr[4]++;
                    }
                    else if (patternCheck == "HTH")
                    {
                        arr[5]++;
                    }
                    else if (patternCheck == "HHT")
                    {
                        arr[6]++;
                    }
                    else if (patternCheck == "HHH")
                    {
                        arr[7]++;
                    }
                }
            }
        }
        cout << N << " ";
        for (int i = 0; i < 8; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
}