#include<stdio.h>
#include<string.h>
int main(){
    int i;
    int b, n;
    int d, c, v;
    int banks[25];
    bool saved=true;
    while(scanf("%d%d", &b, &n) && b!=0 && n!=0){
        saved=true;
        memset(banks, 0, sizeof(banks));
        for(i=0; i<b; i++){
            scanf("%d", &banks[i]);
        }
        for(i=0; i<n; i++){
            scanf("%d%d%d", &d, &c, &v);
            banks[d-1]-=v;
            banks[c-1]+=v;
        }
        for(i=0; i<b; i++){
            if(banks[i]<0){
                saved=false;
            }
        }
        printf("%s\n", (saved ? "S" : "N"));
    }
    return 0;
}
