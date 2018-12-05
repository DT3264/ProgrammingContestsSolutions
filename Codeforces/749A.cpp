#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n/2);
    for(int i=1; i<n/2; i++){
        printf("2 ");
    }
    printf(n%2==0 ? "2" : "3");
    return 0;
}
