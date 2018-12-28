#include<stdio.h>
#include<string.h>
int arr[100001];
int tArr[100001];
void mergeArr(int arr[], int left, int right, int mid){
    for(int i=left; i<=right; i++){
        tArr[i]=arr[i];
    }
    int i=left, j=mid+1;
    int k = left;
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
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        mergeArr(arr, left, right, mid);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    int minN = 1e9;
    if(arr[n-1]-arr[0]<minN){
        minN = arr[n-1]-arr[0];
    }
    if(arr[n-1]-arr[1]<minN){
        minN = arr[n-1]-arr[1];
    }
    if(n>=3){
        if(arr[n-2]-arr[0]<minN){
            minN = arr[n-2]-arr[0];
        }
    }
    printf("%d", minN);
    return 0;
}
