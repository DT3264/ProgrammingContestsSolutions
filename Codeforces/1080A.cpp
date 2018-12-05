#include<stdio.h>
#include<math.h>
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    long long red, green, blue;
    red = n*2;
    green = n*5;
    blue = n*8;
    long long total = ceil((double)red/(double)m) + ceil((double)green/(double)m) + ceil((double)blue/(double)m);
    printf("%lld", total);
    return 0;
}
