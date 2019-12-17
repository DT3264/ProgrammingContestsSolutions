#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        int sLen=s.length();
        if(sLen>=2){
            if(s[sLen-2]=='p' && s[sLen-1]=='o'){
                cout << "FILIPINO\n";
            }
        }
        if(sLen>=4){
            if(s[sLen-4]=='d' && s[sLen-3]=='e' && s[sLen-2]=='s' && s[sLen-1]=='u'){
                cout << "JAPANESE\n";
            }
            if(s[sLen-4]=='m' && s[sLen-3]=='a' && s[sLen-2]=='s' && s[sLen-1]=='u'){
                cout << "JAPANESE\n";
            }
        }
        if(sLen>=5){
            if(s[sLen-5]=='m' && s[sLen-4]=='n' && s[sLen-3]=='i' && s[sLen-2]=='d' && s[sLen-1]=='a'){
                cout << "KOREAN\n";
            }
        }
    }
}
