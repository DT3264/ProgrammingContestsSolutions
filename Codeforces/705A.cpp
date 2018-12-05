#include<stdio.h>
int main(){
    int n, i;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        printf(i%2!=0 ? "I hate ": "I love ");
        printf(i!=n ? "that " : "it");
    }
    return 0;
}
