#include<bits/stdc++.h>
using namespace std;
bool canUse[27];
int main(){
    int n, i;
    int x, y;
    int d, u, r, l;
    string str;
    cin >> n;
    while(n--){
        d=u=l=r=0;
        cin >> str;
        for(i=0; i<str.length(); i++){
            if(str[i]=='D'){
                d++;
            }else if(str[i]=='U'){
                u++;
            }else if(str[i]=='L'){
                l++;
            }else if(str[i]=='R'){
                r++;
            }
        }
        x=min(l, r);
        y=min(u, d);
        if(x>1 && y==0){
            x=1;
        }
        if(y>1 && x==0){
            y=1;
        }
        bool can=true;
        if(x>1 && y==0){
            can=false;
        }
        if(y>1 && x==0){
            can=false;
        }
        if(can){
            l=r=x;
            u=d=y;
            cout << (x*2) + (y*2) << "\n";
            for(i=0; i<x; i++){
                cout << 'L';
            }
            for(i=0; i<y; i++){
                cout << 'U';
            }
            for(i=0; i<x; i++){
                cout << 'R';
            }
            for(i=0; i<y; i++){
                cout << 'D';
            }
            cout << "\n";
        }
        else{
            cout << "0\n";
        }
    }
    cout << "\n";
}
