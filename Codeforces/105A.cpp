#include<stdio.h>
int n, i, t, cont=1;
int arr[1001];
int arrSize;
int main(){
    scanf("%d", &n);
    scanf("%d", &t);
    for(i=1; i<n; i++){
        scanf("%d", &t);
        if(t==1){
            arr[arrSize++]=cont;
            cont=1;
        }
        else{
            cont++;
        }
    }
    if(cont>0){
        arr[arrSize++]=cont;
    }
    printf("%d\n", arrSize);
    for(i=0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }
}
