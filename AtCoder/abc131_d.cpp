#include<bits/stdc++.h>
using namespace std;
struct job{
    long long t;
    long long dL;
};
bool sortByDeadLine(job j1, job j2){
    return j1.dL<=j2.dL;
}
job jobs[200001];
job tArr[200001];
void mergeArr(job arr[200001], int left, int right, int mid){
    for(int i=left; i<=right; i++){
        tArr[i]=arr[i];
    }
    int i=left, j=mid+1;
    int k=left;
    while(i<=mid && j<=right){
        if(tArr[i].dL<tArr[j].dL){
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

void mergeSort(job arr[200001], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        mergeArr(arr, left, right, mid);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long t, dL;
    for(int i=0; i<n; i++){
        cin>>jobs[i].t>>jobs[i].dL;
    }
    mergeSort(jobs, 0, n-1);
    long long sum=0;
    bool canFinish=true;
    for(int i=0; i<n; i++){
        //printf("%d\n", i);
        sum+=jobs[i].t;
        if(sum>jobs[i].dL){
            canFinish=false;
        }
    }
    cout<<(canFinish ? "Yes" : "No");
    return 0;
}
