#include<bits/stdc++.h>
using namespace std;
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    string str;
    int n, i;
    cin >> n;
    cin >> str;
    int zeros=0;
    int ones=0;
    for(i=0; i<n; i++){
        if(str[i]=='0'){
            zeros++;
        }
        else{
            ones++;
        }
    }
    if(ones==zeros){
        cout << "2\n";
        cout << str[0] << " ";
        for(i=1; i<str.length(); i++){
            cout << str[i];
        }
        cout << "\n";
    }
    else{
        cout << "1\n";
        for(i=0; i<str.length(); i++){
            cout << str[i];
        }
        cout << "\n";
    }
    return 0;
}
