#include<stdio.h>
int main(){
    int i, j, tmp;
    int arr[3];
    for(i=0; i<3; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            if(arr[j]>arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    printf("%d", (arr[2]-arr[1])+(arr[1]-arr[0]));
    return 0;
}
