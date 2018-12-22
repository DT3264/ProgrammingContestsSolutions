#include<stdio.h>
int main(){
    int n, a, b;
    int i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d", &a, &b);
        for(j=0; j<a; j++){
            printf("%c", (j%b)+'a');
        }
        printf("\n");
    }
    return 0;
}
