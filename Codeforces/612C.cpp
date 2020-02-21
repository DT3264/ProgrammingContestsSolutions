#include<bits/stdc++.h>
using namespace std;
bool isOpen(char c){
    return c=='[' || c=='{' || c=='(' || c=='<';
}
bool isClose(char c){
    return c==']' || c=='}' || c==')' || c=='>';
}
bool areSameType(char c1, char c2){
    return (c1=='[' && c2==']') || (c1=='{' && c2=='}') || (c1=='(' && c2==')' || (c1=='<' && c2=='>'));
}
int main(){
    char c;
    string s;
    int i, ans=0;
    bool valid=true;
    stack<char> myStack;
    cin >> s;
    for(i=0; i<s.length(); i++){
        c = s[i];
        if(isOpen(s[i])){
            myStack.push(c);
        }
        else if(isClose(s[i])){
            if(myStack.size()>0){
                if(!areSameType(myStack.top(), s[i])){
                    ans++;
                }
                myStack.pop();
            }
            else{
                valid=false;
            }
        }
    }
    if(myStack.size()==0 && valid){
        cout << ans << endl;
    }
    else{
        cout << "Impossible\n";
    }
return 0;
}
