#include<stdio.h>
#include<algorithm>
int arr[4];
int main(){
    int i;
    for(i=0; i<4; i++){
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr+4);
    printf("%d %d %d", arr[3]-arr[0], arr[3]-arr[1], arr[3]-arr[2]);
}
