#include<stdio.h>
int arr[3];

void sortArr(int arr[]){
    int tmp;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            if(arr[j]>arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}

int main (){
    int n;
    int i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<3; j++){
            scanf("%d", &arr[j]);
        }
        sortArr(arr);
        printf("Case %d: %d\n", i+1, arr[1]);
    }
    return 0;
}
