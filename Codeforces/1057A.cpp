#include<stdio.h>
int n, arr[200000], arr2[200000], posArr=0;
int main (){
    int n, i;
    scanf("%d", &n);
    for(i=2; i<n+1; i++){
        scanf("%d", &arr[i]);
        ///printf("read %d at %d\n", arr[i], i);
    }
    int actualPos = n;
    arr2[posArr++]=n;
    while(actualPos>0){
        ///printf("%d ", arr[actualPos]);
        actualPos=arr[actualPos];
        arr2[posArr++]=actualPos;
    }
    for(i=posArr-2; i>=0; i--){
        printf("%d ", arr2[i]);
    }
    return 0;
}
