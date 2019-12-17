#include<bits/stdc++.h>
using namespace std;
int main(){
    int l=0, r=0, u=0, d=0;
    int n, ans=0;
    string s;
    cin >> n >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='L'){
            l++;
        }
        else if(s[i]=='R'){
            r++;
        }
        else if(s[i]=='U'){
            u++;
        }
        else if(s[i]=='D'){
            d++;
        }
    }
    int x=min(u, d)*2;
    int y=min(r, l)*2;
    ans=x+y;
    printf("%d\n", ans);
}
