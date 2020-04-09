#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string in;
    while(getline(cin, in)){
        if(in=="DONE"){
            break;
        }
        string str="";
        for(char c : in){
            if(c>='A' && c<='Z'){
                str+=c+32;
            }
            if(c>='a' && c<='z'){
                str+=c;
            }
        }
        bool isPalindromo=true;
        for(int i=0; i<str.size(); i++){
            if(str[i]!=str[str.size()-1-i]){
                isPalindromo=false;
            }
        }
        cout << (isPalindromo ? "You won't be eaten!" : "Uh oh..") << "\n";
    }
	return 0;
}
