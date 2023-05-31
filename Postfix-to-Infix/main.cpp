#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
string s;
stack <string> A, B;
int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '*' && s[i] != '+' && s[i] != '-' && s[i] != '/' && s[i] != '^' && s[i] != '%'){
            string SS(1, s[i]);
            A.push(SS);
        }
        else{
            string temp1 = A.top();
            A.pop();
            string temp2 = A.top();
            A.pop();
            A.push("("+temp2 + s[i] + temp1+")");
        }
    }
    cout << A.top();
}
