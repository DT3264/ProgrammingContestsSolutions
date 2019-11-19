#include <bits/stdc++.h>
using namespace std;
int main(){
    int k, l, m;
    int c, i;
    bool np[1000001];
    scanf("%d%d%d", &k, &l, &m);
    memset(np, 0, sizeof(np));
    np[1]=1;
    np[k]=1;
    np[l]=1;
    for(i=1; i<=1000000; i++){
        if(i-1>=1){
            if(np[i-1]==0){
                np[i]=1;
            }
        }
        if(i-k>=1){
            if(np[i-k]==0){
                np[i]=1;
            }
        }
        if(i-l>=1){
            if(np[i-l]==0){
                np[i]=1;
            }
        }
    }
    while(m--){
        scanf("%d", &c);
        printf("%c", np[c] ? 'A' : 'B');
    }
    printf("\n");
}
