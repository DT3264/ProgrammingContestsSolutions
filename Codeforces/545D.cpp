#include<stdio.h>
long long arr[100001];
long long time[100001];

long long tArr[100001];
void mergeArr(long long arrL[], long long left, long long right, long long mid){
    for(long long i=left; i<=right; i++){
        tArr[i]=arrL[i];
    }
    long long i=left, j=mid+1;
    long long k=left;
    while(i<=mid && j<=right){
        if(tArr[i]<tArr[j]){
            arrL[k++]=tArr[i++];
        }
        else{
            arrL[k++]=tArr[j++];
        }
    }
    while(i<=mid){
        arrL[k++]=tArr[i++];
    }
    while(j<=right){
        arrL[k++]=tArr[j++];
    }
}

void mergeSort(long long arrL[], long long left, long long right){
    if(left<right){
        long long mid = (left+right)/2;
        mergeSort(arrL, left, mid);
        mergeSort(arrL, mid+1, right);
        mergeArr(arrL, left, right, mid);
    }
}

int main(){
    long long n, i;
    scanf("%lld", &n);
    for(i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    long long happy=1;
    long long contTime=arr[0];
    for(i=1; i<n; i++){
        if(contTime<=arr[i]){
            happy++;
            contTime+=arr[i];
        }
    }
    printf("%lld", happy);
    return 0;
}
