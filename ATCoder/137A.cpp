#include <stdio.h>
#include <algorithm>
int main(){
    int a, b, maxN=-10000000;
    scanf("%d%d", &a, &b);
    maxN=std::max(maxN, a+b);
    maxN=std::max(maxN, a-b);
    maxN=std::max(maxN, a*b);
    printf("%d\n", maxN);
    return 0;
}
