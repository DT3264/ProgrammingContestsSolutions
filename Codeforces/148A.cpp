#include<stdio.h>

bool dragons[100001];
int cont=0;

int main(){
    int a, b, c, d, n, i;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);
    for(i=a; i<=n; i+=a) dragons[i]=true;
    for(i=b; i<=n; i+=b) dragons[i]=true;
    for(i=c; i<=n; i+=c) dragons[i]=true;
    for(i=d; i<=n; i+=d) dragons[i]=true;
    for(i=1; i<=n; i++){ if(dragons[i]) cont++; }
    printf("%d\n", cont);
    return 0;

}
