#include<stdio.h>
int n, t, i, j;
long long arr[3];
int main(){
    scanf("%d", &n);
    for(i=0; i<3; i++){
        for(j=0; j<n-i; j++){
            scanf("%d", &t);
            arr[i]+=t;
        }
    }
    for(i=0; i<2; i++){
        printf("%d\n", arr[i]-arr[i+1]);
    }
    return 0;
}
