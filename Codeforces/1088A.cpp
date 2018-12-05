#include<stdio.h>
#include<algorithm>
int main(){
    int n, a, b;
    scanf("%d", &n);
    for(a=n; a>=1; a--){
        for(b=1; b<=n; b++){
            if(b%a==0 && a*b>n && (double)a/(double)b<(double)n){
                printf("%d %d", b, a);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}
