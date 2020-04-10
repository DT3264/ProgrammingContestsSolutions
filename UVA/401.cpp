#include<bits/stdc++.h>
using namespace std;
char getMirror(char c){
    if(c=='A') return 'A';
    if(c=='E') return '3';
    if(c=='H') return 'H';
    if(c=='I') return 'I';
    if(c=='J') return 'L';
    if(c=='L') return 'J';
    if(c=='M') return 'M';
    if(c=='O') return 'O';
    if(c=='S') return '2';
    if(c=='T') return 'T';
    if(c=='U') return 'U';
    if(c=='V') return 'V';
    if(c=='W') return 'W';
    if(c=='X') return 'X';
    if(c=='Y') return 'Y';
    if(c=='Z') return '5';
    if(c=='1') return '1';
    if(c=='2') return 'S';
    if(c=='3') return 'E';
    if(c=='5') return 'Z';
    if(c=='8') return '8';
    return '.';
}
bool isPalindromo(string str){
    for(int i=0; i<str.size(); i++){
        if(str[i]!=str[str.size()-1-i]){
            return false;
        }
    }
    return true;
}
bool isMirror(string str){
    int n = str.size();
    string str2 = str;
    for(int i=0; i<n; i++){
        str2[i]=getMirror(str[i]);
    }
    for(int i=0; i<n; i++){
        if(str[i]!=str2[n-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int firstCase=true;
    while(cin >> str){
        firstCase=false;
        bool palindromo = isPalindromo(str);
        bool mirror = isMirror(str);
        cout << str;
        if(palindromo && mirror){
            cout << " -- is a mirrored palindrome.";
        }
        if(!palindromo && mirror){
            cout << " -- is a mirrored string.";
        }
        if(palindromo && !mirror){
            cout << " -- is a regular palindrome.";
        }
        if(!palindromo && !mirror){
            cout << " -- is not a palindrome.";
        }
        cout << "\n\n";
    }
	return 0;
}
