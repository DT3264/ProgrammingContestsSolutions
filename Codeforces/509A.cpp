#include<stdio.h>
int n, arr[10][10];
int main(){
    int i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        arr[i][0]=1;
        arr[0][i]=1;
    }
    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    printf("%d", arr[n-1][n-1]);
}
