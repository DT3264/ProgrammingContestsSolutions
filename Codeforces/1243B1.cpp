#include<bits/stdc++.h>
using namespace std;
int main(){
    int p1=-1, p2=-1;
    int t, n, i;
    cin >> t;
    string s1, s2;
    while(t--){
        p1=-1;
        p2=-1;
        cin >> n >> s1 >> s2;
        for(i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                if(p1==-1){
                    p1=i;
                }
                else if(p2==-1){
                    p2=i;
                    break;
                }
            }
        }
        if(p1!=-1 && p2!=-1){
            char tmp=s1[p1];
            s1[p1]=s2[p2];
            s2[p2]=tmp;
        }
        bool valid=true;
        for(i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                valid=false;
            }
        }
        cout << (valid ? "Yes" : "No" ) << "\n";
    }

}