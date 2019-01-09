#include<stdio.h>
#include<string.h>
int n, m;
int ans=1e9;
int actualAns=1e9;
int reached[20001];

void reachM(int x, int press){
    if(x<1 || x>20000){
        return;
    }
    if(press>=reached[x]&& reached[x]!=-1){
        return;
    }
    reached[x]=press;
    if(x==m){
        ans=press;
        return;
    }
    reachM(x-1, press+1);
    reachM(x*2, press+1);
}

int main(){
    scanf("%d%d", &n, &m);
    memset(reached, -1, sizeof(reached));
    reachM(n, 0);
    printf("%d", ans);
    return 0;
}
