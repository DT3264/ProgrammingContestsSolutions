#include<stdio.h>
bool apples[101];
int main (){
    int n, a, b, i, t;
    scanf("%d%d%d", &n, &a, &b);
    for(i=0; i<a; i++){
        scanf("%d", &t);
        apples[t]=true;
    }
    for(i=0; i<b; i++){
        scanf("%d", &t);
    }
    for(i=1; i<=n; i++){
        printf("%d ", (apples[i] ? 1 : 2));
    }
    return 0;
}
