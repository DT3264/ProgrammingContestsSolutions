#include<stdio.h>
int main(){
    int n, p, k, i;
    scanf("%d%d%d", &n, &p, &k);
    if(p-k>1) printf("<< ");
    for(i=p-k; i<=p+k; i++){
        if(i>=1 && i<=n)
        printf((i==p ? "(%d) " : "%d "), i);
    }
    if(p+k<n) printf(">>");
    return 0;
}
