#include<stdio.h>
#include<algorithm>
using namespace std;
struct kid{
    int id;
    int score;
}kids[1000];
int i, j, n, t;

kid tArr[1000];
void mergeArr(kid arr[], int left, int right, int mid, bool sortByScore){
    for(int i=left; i<=right; i++){
        tArr[i]=arr[i];
    }
    int i=left, j=mid+1;
    int k=left;
    while(i<=mid && j<=right){
        if(sortByScore){
            if(tArr[i].score>tArr[j].score){
                arr[k++]=tArr[i++];
            }
            else{
                arr[k++]=tArr[j++];
            }
        }
        else{
            if(tArr[i].id<tArr[j].id){
                arr[k++]=tArr[i++];
            }
            else{
                arr[k++]=tArr[j++];
            }
        }
    }
    while(i<=mid){
        arr[k++]=tArr[i++];
    }
    while(j<=right){
        arr[k++]=tArr[j++];
    }
}

void mergeSort(kid arr[], int left, int right, bool sortByScore){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr, left, mid, sortByScore);
        mergeSort(arr, mid+1, right, sortByScore);
        mergeArr(arr, left, right, mid, sortByScore);
    }
}

int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        kids[i].id=i+1;
        for(j=0; j<4; j++){
            scanf("%d", &t);
            kids[i].score+=t;
        }
    }
    mergeSort(kids, 0, n-1, true);
    int actualScore=kids[0].score, cantSameScore=1;
    for(i=1; i<n; i++){
        if(kids[i].score==actualScore){
            cantSameScore++;
        }
        else{
            if(cantSameScore>1){
                mergeSort(kids, i-cantSameScore, i-1, false);
            }
            actualScore=kids[i].score;
            cantSameScore=1;
        }
    }
    if(cantSameScore>1){
        mergeSort(kids, i-cantSameScore, i-1, false);
    }
    for(i=0; i<n; i++){
        //printf("%d %d\n", kids[i].id, kids[i].score);
        if(kids[i].id==1){
            printf("%d", i+1);
            i=n;
        }
    }
    return 0;
}
