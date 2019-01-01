#include<stdio.h>
int n, k;
int arr[100];
int main(){
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int left=0, right=n-1;
    int cont=0;
    while(left<=right){
        if(arr[left]<=k){
            cont++;
            left++;
        }
        else break;
    }
    while(left<=right){
        if(arr[right]<=k){
            cont++;
            right--;
        }
        else break;
    }
    printf("%d", cont);
    return 0;
}
