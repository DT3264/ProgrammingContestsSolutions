#include <stdio.h>
#include <algorithm>
int main(){
    int k, x, i;
    scanf("%d%d", &k, &x);
    for(i=x-k+1; i<x; i++){
        printf("%d ", i);
    }
    for(i=x; i<k+x; i++){
        printf("%d ", i);
    }
    return 0;
}
