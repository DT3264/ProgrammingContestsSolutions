#include<stdio.h>
int main(){
    int n, i, a, contA=0, b, contB=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d", &a, &b);
        if(a>b) contA++;
        else if(b>a) contB++;
    }
    if(contA==contB) printf("Friendship is magic!^^");
    else printf(contA>contB ? "Mishka" : "Chris");
    return 0;
}

