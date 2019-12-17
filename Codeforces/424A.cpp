#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i;
    int d=0, u=0;
    int ans=0;
    string s;
    cin >> n >> s;
    for(i=0; i<s.length(); i++){
        if(s[i]=='x'){
            d++;
        }
        else{
            u++;
        }
    }
    if(d>u){
        for(i=0; i<s.length() && d>u; i++){
            if(s[i]=='x'){
                s[i]='X';
                d--;
                u++;
                ans++;
            }
        }
    }
    else if(u>d){
        for(i=0; i<s.length() && u>d; i++){
            if(s[i]=='X'){
                s[i]='x';
                d++;
                u--;
                ans++;
            }
        }
    }
    cout << ans << "\n";
    cout << s << "\n";
}
