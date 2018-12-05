#include<stdio.h>
#include<algorithm>
int main(){
    int n, m, i;
    int arr[100001];
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr+n);
    int toSubstractAct=0;
    int toSubstractNext=0;
    i=0;
    while(i<n && m>0){
        while(i<n && arr[i]-toSubstractAct<=0){
            i++;
        }
        if(i>=n){
            break;
        }
        if(arr[i]!=0) toSubstractNext=arr[i];
        arr[i]-=toSubstractAct;
        printf("%d\n", arr[i]);
        toSubstractAct=toSubstractNext;
        i++;
        m--;
    }
    while(m>0){
        printf("0\n");
        m--;
    }
    return 0;
}
