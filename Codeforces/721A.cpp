#include<stdio.h>
int n, arr[100];
int arrSize;
char str[101];
int main(){
    int i, blackSeq=0;
    scanf("%d%s", &n, str);
    for(i=0; i<n; i++){
        if(str[i]=='B'){
            blackSeq++;
        }
        if(str[i]=='W' && blackSeq>0){
            arr[arrSize++]=blackSeq;
            blackSeq=0;
        }
    }
    if(blackSeq>0){
        arr[arrSize++]=blackSeq;
        blackSeq=0;
    }
    printf("%d\n", arrSize);
    for(i=0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }
}
