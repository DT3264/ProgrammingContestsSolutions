#include<stdio.h>
int n, t;
int main(){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        printf("%d ", (t%2!=0 ? t : t-1));
    }

}
