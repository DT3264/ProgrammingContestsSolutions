#include<stdio.h>
#include<math.h>
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int x = floor((double)n/(double)k)+1;
    printf("%d", x*k);
}
