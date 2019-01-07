#include<stdio.h>
int n, arr[1000000];

int tArr[1000000];
void mergeArr(int arr[], int left, int right, int mid){
    for(int i=left; i<=right; i++){
        tArr[i]=arr[i];
    }
    int i=left, j=mid+1;
    int k=left;
    while(i<=mid && j<=right){
        if(tArr[i]<tArr[j]){
            arr[k++]=tArr[i++];
        }
        else{
            arr[k++]=tArr[j++];
        }
    }
    while(i<=mid){
        arr[k++]=tArr[i++];
    }
    while(j<=right){
        arr[k++]=tArr[j++];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        mergeArr(arr, left, right, mid);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    printf("%d", arr[(n-1)/2]);
    return 0;
}
