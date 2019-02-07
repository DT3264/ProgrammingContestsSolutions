#include<stdio.h>
int n;
long long cont;
const int ARR_SIZE=1e6;
long long arr[ARR_SIZE];
long long tArr[ARR_SIZE];
void mergeArr(long long lArr[], int left, int right, int mid){
    for(int i=left; i<=right; i++){
        tArr[i]=lArr[i];
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
void mergeSort(long long lArr[], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(lArr, left, mid);
        mergeSort(lArr, mid+1, right);
        mergeArr(lArr, left, right, mid);
    }
}
int main (){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    for(i=0; i<n/2; i++){
        cont+=(arr[i]+arr[n-i-1])*(arr[i]+arr[n-i-1]);
    }
    printf("%lld", cont);
    return 0;
}
