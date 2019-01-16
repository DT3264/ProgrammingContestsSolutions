#include<stdio.h>
#include<string.h>
int n, k;
int arr[101];
int origArr[101];

int res[101];
int contRes;

int tArr[101];
void mergeArr(int sArr[], int left, int right, int mid){
    for(int i=left; i<=right; i++){
        tArr[i]=sArr[i];
    }
    int i=left, j=mid+1;
    int k=left;
    while(i<=mid && j<=right){
        if(tArr[i]<tArr[j]){
            sArr[k++]=tArr[i++];
        }
        else{
            sArr[k++]=tArr[j++];
        }
    }
    while(i<=mid){
        sArr[k++]=tArr[i++];
    }
    while(j<=right){
        sArr[k++]=tArr[j++];
    }
}

void mergeSort(int sArr[], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(sArr, left, mid);
        mergeSort(sArr, mid+1, right);
        mergeArr(sArr, left, right, mid);
    }
}

void findN(int x){
    for(int i=0; i<n; i++){
        if(origArr[i]==x){
            res[contRes++]=i+1;
            return;
        }
    }
}

int main (){
    int i;
    scanf("%d%d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    memcpy(origArr, arr, sizeof(arr));
    mergeSort(arr, 0, n-1);
    for(i=0; i<n; i++){
        if(arr[i]!=arr[i-1]){
            findN(arr[i]);
        }
    }
    printf("%s\n", (contRes>=k ? "YES" : "NO"));
    if(contRes>=k){
        for(i=0; i<k; i++){
            printf("%d ", res[i]);
        }
    }
    return 0;
}
