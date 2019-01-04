#include<stdio.h>
int n, m, t, arr[10];
bool buk[10];
int main(){
    int i;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<m; i++){
        scanf("%d", &t);
        buk[t]=true;
    }
    for(i=0; i<n; i++){
        if(buk[arr[i]]){
            printf("%d ", arr[i]);
        }
    }
}
