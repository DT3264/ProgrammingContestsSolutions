#include<stdio.h>
int main(){
    int i, n, m, total=0;
    int arr[101];
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        total+=arr[i];
    }
    i=0;
    int lastChild;
    while(total>0){
        if(arr[i]>0){
            if(arr[i]-m<0) total-=arr[i];
            else total-=m;
            arr[i]-=m;
            lastChild = i+1;
        }
        i++;
        if(i==n) i=0;
    }
    printf("%d\n", lastChild);
    return 0;
}
