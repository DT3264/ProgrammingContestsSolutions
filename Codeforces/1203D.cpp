#include <bits/stdc++.h>
using namespace std;
int lMost[200001], rMost[200001];
int main(){
    int i;
    int s1Len, s2Len;
    int s2Pos=0;
    string s1, s2;
    cin >> s1 >> s2;
    s1Len=s1.length();
    s2Len=s2.length();
    for(i=0; i<s1Len; i++){
        if(s1[i]==s2[s2Pos]){
            lMost[s2Pos]=i;
            s2Pos++;
        }
    }
    s2Pos=s2Len-1;
    for(i=s1Len-1; i>=0; i--){
        if(s1[i]==s2[s2Pos]){
            rMost[s2Pos]=i;
            s2Pos--;
        }
    }
    int maxN=0;
    for(i=1; i<s2Len; i++){
        maxN=max(maxN, rMost[i]-lMost[i-1]-1);
    }
    maxN=max(maxN, rMost[0]);
    maxN=max(maxN, s1Len-lMost[s2Len-1]-1);
    printf("%d\n", maxN);
}
