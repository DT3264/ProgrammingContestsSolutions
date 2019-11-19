#include<bits/stdc++.h>
using namespace std;
struct P{
    int n1;
    int n2;
};
string s, t;
vector<P> ans;
void swapS(int sP, int tP){
    char tmp=s[sP];
    s[sP]=t[tP];
    t[tP]=tmp;
    ans.push_back({sP+1, tP+1});
}
int main(){
    //freopen("out.txt", "w", stdout);
    bool can;
    int cases, n, i, j;
    cin >> cases;
    while(cases--){
        can=true;
        ans.clear();
        cin >> n >> s >> t;
        for(i=0; i<n && can; i++){
            if(s[i]!=t[i]){///Encontrar a t[i] en t[x]; x>i
                for(j=i+1; j<n; j++){
                    if(t[j]==t[i]){
                        swapS(i, j);///Pasar de t[x] a s[i]
                        j=n;
                    }
                }
            }
            if(s[i]!=t[i]){///Encontrar a t[i] en s[x]; x>=i
                for(j=i; j<n; j++){
                    if(s[j]==t[i]){
                        swapS(j, j);///Pasar de s[x] a t[x]
                        swapS(i, j);///Pasar de t[x] a s[i]
                        j=n;
                    }
                }
            }
            if(s[i]!=t[i]){
                can=false;
            }
        }
        if(can && ans.size()<=2*n){
            printf("Yes\n%d\n", ans.size());
            for(P p : ans){
                printf("%d %d\n", p.n1, p.n2);
            }
        }
        else{
            printf("No\n");
        }
    }
}