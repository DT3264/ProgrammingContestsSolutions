#include<stdio.h>
int main(){
    int n, i;
    double t, total=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%lf", &t);
        total+=t;
    }
    total/=n;
    printf("%.12f", total);
    return 0;
}
