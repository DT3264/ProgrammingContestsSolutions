#include<stdio.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int actualSteps = (n+1)/2;
    while(actualSteps%m!=0 && actualSteps<=n)actualSteps++;
    printf("%d\n", (actualSteps<=n? actualSteps : -1));
    return 0;
}
