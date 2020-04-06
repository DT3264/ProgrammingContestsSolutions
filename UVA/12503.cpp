#include <bits/stdc++.h>
using namespace std;
int main(){
    int cases, lines;
    cin >> cases;
    string str;
    char caseAtI[101];
    while(cases--){
        int ans=0, pos;
        cin >> lines;
        memset(caseAtI, 0, sizeof(caseAtI));
        for(int i=0; i<lines; i++){
            cin >> str;
            if(str == "LEFT"){
                caseAtI[i]='L';
                ans--;
            }
            else if(str == "RIGHT"){
                caseAtI[i]='R';
                ans++;
            }
            else if(str == "SAME"){
                cin >> str;
                cin >> pos;
                pos--;
                caseAtI[i]=caseAtI[pos];
                if(caseAtI[i]=='L'){
                    ans--;
                }
                else if(caseAtI[i]=='R'){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
