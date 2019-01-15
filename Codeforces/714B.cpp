#include<stdio.h>
int tArr[1000001];
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
int gArr[1000001];
int difN[3];
int main (){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &gArr[i]);
    }
    mergeSort(gArr, 0, n-1);
    int contN=1;
    difN[0]=gArr[0];
    for(i=1; i<n; i++){
        if(gArr[i]>gArr[i-1]){
            difN[contN]=gArr[i];
            contN++;
        }
    }
    bool canBeEqual=false;
    if(contN<3){
        canBeEqual=true;
    }
    if(contN==3){
        if(difN[1]-difN[0]==difN[2]-difN[1]){
            canBeEqual=true;
        }
    }
    printf("%s\n", (canBeEqual ? "YES" : "NO"));
    return 0;
}
