#include<stdio.h>
int n, arr[110][110];
bool used[110][110];
int total;
int main(){
    int i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(i=0; i<n; i++){
        if(!used[i][i]){
            total+=arr[i][i];
            used[i][i]=true;
        }
        if(!used[i][n-i-1]){
            total+=arr[i][n-i-1];
            used[i][n-i-1]=true;
        }
        if(!used[i][n/2]){
            total+=arr[i][n/2];
            used[i][n/2]=true;
        }
        if(!used[n/2][i]){
            total+=arr[n/2][i];
            used[n/2][i]=true;
        }
    }
    printf("%d", total);
    return 0;
}
