#include<stdio.h>
int arr[101];
int main(){
    int n, m, x, y;
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        for(j=x; j<=y; j++) arr[j]++;
    }
    int cont=0;
    for(i=1; i<=m; i++){
        if(arr[i]==0) cont++;
    }
    printf("%d\n", cont);
    for(i=1; i<=m; i++){
        if(arr[i]==0) printf("%d ", i);
    }
    return 0;
}
