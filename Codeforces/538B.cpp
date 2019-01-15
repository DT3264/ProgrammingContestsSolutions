#include<stdio.h>
int arr[10];
int digits;
int cantN;

void reverseArr(int toReverse[]){
    int tArr[10];
    int i;
    for(i=0; i<digits; i++){
        tArr[i]=arr[digits-i-1];
    }
    for(i=0; i<digits; i++){
        arr[i]=tArr[i];
    }
}

int main (){
    int n, i, j;
    scanf("%d", &n);
    while(n>0){
        if(cantN<n%10){
            cantN=n%10;
        }
        arr[digits++]=n%10;
        n/=10;
    }
    reverseArr(arr);
    printf("%d\n", cantN);
    bool canPrint;
    for(i=0; i<cantN; i++){
        canPrint=false;
        for(j=0; j<digits; j++){
            if(arr[j]>0 && !canPrint){
                canPrint=true;
            }
            if(canPrint){
                printf("%d", (arr[j]>=1 ? 1 : 0));
            }
            arr[j]--;
        }
        printf(" ");
    }
    return 0;
}
