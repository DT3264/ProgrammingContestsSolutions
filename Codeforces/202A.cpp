#include<bits/stdc++.h>
using namespace std;
int n;
bool used[10];
string s;
string bestPalindromo="";
bool isPalindromo(string s){
    string s2=s;
    reverse(s2.begin(), s2.end());
    return s==s2;
}
void permu(int ind){
    if(ind>=s.length()){
        string tmp;
        for(int i=0; i<s.length(); i++){
            if(used[i]){
                tmp+=s[i];
            }
        }
        //cout << tmp << endl;
        if(isPalindromo(tmp)){
            if(bestPalindromo==""){
                bestPalindromo=tmp;
            }
            else{
                if(tmp>bestPalindromo){
                    bestPalindromo=tmp;
                }
            }
        }
        return;
    }
    used[ind]=true;
    permu(ind+1);
    used[ind]=false;
    permu(ind+1);
}

int main(){
    cin >> s;
    //cout << "*" << s << "*" << endl;
    permu(0);
    cout << bestPalindromo << endl;
    return 0;
}
