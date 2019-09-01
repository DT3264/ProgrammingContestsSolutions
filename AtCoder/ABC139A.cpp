#include <bits/stdc++.h>
using namespace std;
int main(){
    int i, cont=0;
    string s, t;
    cin >> s >> t;
    for(i=0; i<3; i++){
        if(s[i]==t[i]){
            cont++;
        }
    }
    cout << cont << "\n";
}
