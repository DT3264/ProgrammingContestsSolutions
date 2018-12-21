#include<stdio.h>
struct tree{
    int pos;
    int apples;
}trees[110];
int n, leftInd, rightInd;

void mergeArr(tree arr[], int left, int right, int mid){
    tree tmpArr[110];
    for(int i=left; i<=right; i++){
        tmpArr[i]=arr[i];
    }
    int i=left, j=mid+1;
    int k = left;
    while(i<=mid && j<=right){
        if(tmpArr[i].pos<tmpArr[j].pos){
            arr[k++]=tmpArr[i++];
        }
        else{
            arr[k++]=tmpArr[j++];
        }
    }
    while(i<=mid){
        arr[k++]=tmpArr[i++];
    }
    while(j<=right){
        arr[k++]=tmpArr[j++];
    }
}

void mergeSort(tree arr[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        mergeArr(arr, left, right, mid);
    }
}

int grabApples(bool startToLeft, int left, int righ){
    bool canGrabApples=true;
    bool turnOfLeft = startToLeft;
    int totalApples=0;
    while(canGrabApples){
        if(turnOfLeft){
            if(left>=0){
                totalApples+=trees[left--].apples;
            }
            else{
                canGrabApples=false;
            }
        }
        else{
            if(righ<n){
                totalApples+=trees[righ++].apples;
            }
            else{
                canGrabApples=false;
            }
        }
        turnOfLeft=!turnOfLeft;
    }
    return totalApples;
}

int maxN(int a, int b){
    return (a>b ? a : b);
}

int main(){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d", &trees[i].pos, &trees[i].apples);
    }
    trees[n].pos=0;
    trees[n].apples=0;
    n++;
    mergeSort(trees, 0, n-1);
    for(i=0; i<n; i++){
        if(trees[i].pos==0){
            leftInd=i-1;
            rightInd=i+1;
            break;
        }
    }
    int ans1 = grabApples(true, leftInd, rightInd);
    int ans2 = grabApples(false, leftInd, rightInd);
    printf("%d", maxN(ans1, ans2));
    return 0;
}
