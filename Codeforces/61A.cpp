#include<stdio.h>
#include<iostream>
using namespace std;
int main (){
    string s1, s2;
    cin >> s1 >> s2;
    int n;
    for(int i=0; i<s1.length(); i++){
        n=0;
        n+=s1[i]=='1' ? 1:0;
        n+=s2[i]=='1' ? 1:0;
        cout << (n==1?'1':'0');
    }
    return 0;
}
