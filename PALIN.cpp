#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
bool isPalindrome(string str){
    string copy=str;
    reverse(str.begin(),str.end());
    if(copy==str){
        return true;
    }
    return false;
}