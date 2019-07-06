#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i;
    int MAX = (1e5)+1;
    int arr[MAX];
    scanf("%d", &n);
    int maxN=-1;
    int maxInd=-1;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>=0){
            arr[i]=-arr[i]-1;
        }
        if(abs(arr[i])>maxN){
            maxN=abs(arr[i]);
            maxInd=i;
        }
    }
    if(n%2!=0){
        arr[maxInd]=-arr[maxInd]-1;
    }
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
