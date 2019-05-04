#include<iostream>
using namespace std;
int main(){
    int i;
    string str;
    string key;
    string ans;
    cin >> str >> key;
    int firstKeyLen=key.length();
    for(i=0; i<str.length(); i++){
        char nextChar=str[i]-key[i]+'A';
        if(nextChar<'A'){
            nextChar+=26;
        }
        ans+=nextChar;
        key+=nextChar;
    }
    cout << ans;
    return 0;
}
