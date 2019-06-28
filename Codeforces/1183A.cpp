#include <bits/stdc++.h>
#include<string>
using namespace std;
bool interesting(int n){
    string s=to_string(n);
    int x=0;
    for(int i=0; i<s.length(); i++){
        x+=s[i]-'0';
    }
    //cout << "*" << s << "*" << n << "-" << x << endl;
    return x%4==0;
}
int main(){
    int n;
    cin >> n;
    while(!interesting(n)){
        n++;
    }
    cout << n << endl;
    return 0;
}