#include<stdio.h>
int main(){
    int n, arr[100], i, t;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        arr[t-1]=i+1;
    }
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
