#include<stdio.h>
int main(){
    int n, i, a, b, c;
    int actualCase=1;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d%d", &a, &b, &c);
        printf("Case %d: %s\n", actualCase++, (a<=20 && b<=20 && c<=20 ? "good" : "bad"));
    }
    return 0;
}

