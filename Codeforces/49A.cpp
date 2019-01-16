#include<iostream>
#include<string>
using namespace std;

bool isVowel(char t1, char t2){
    return t1==t2 || t1==t2-32;
}

int main (){
    int i;
    string str;
    getline(cin, str);
    bool endsVowel=false;
    for(i=str.length()-1; i>=0; i--){
        if(str[i]!='?' && str[i]!=' '){
            if(isVowel(str[i], 'a') ||
               isVowel(str[i], 'e') ||
               isVowel(str[i], 'i') ||
               isVowel(str[i], 'y') ||
               isVowel(str[i], 'o') ||
               isVowel(str[i], 'u')){
                endsVowel=true;
            }
            break;
        }
    }
    cout << (endsVowel ? "YES" : "NO");
    return 0;
}
