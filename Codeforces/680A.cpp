#include<stdio.h>
#include<algorithm>
int arr[5];
int i, total;
int main (){
    for(i=0; i<5; i++){
        scanf("%d", &arr[i]);
        total+=arr[i];
    }
    std::sort(arr, arr+5);
    int toDel1=0, toDel2=0;
    for(i=4; i>=2; i--){
        if(arr[i]==arr[i-1] && arr[i-1]==arr[i-2]){
            toDel1=arr[i]*3;
            break;
        }
    }
    for(i=4; i>=1; i--){
        if(arr[i]==arr[i-1]){
            toDel2=arr[i]*2;
            break;
        }
    }
    int res=std::max(toDel1, toDel2);
    printf("%d", total-res);
    return 0;
}
