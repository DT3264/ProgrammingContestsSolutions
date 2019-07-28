#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool isSorted(int *arr, int n){
    //printf("%d ", arr[0]);
    for(int i=1; i<n; i++){
      //  printf("%d ", arr[i]);
        if(arr[i]!=arr[i-1]+1){
        //    printf("\n");
            return false;
        }
    }
    //printf("\n");
    return true;
}
int main(){
    int n, i, j, arr[51], tArr[51];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    bool can=false;
    if(isSorted(arr, n)){
        can=true;
    }
    for(i=0; i<n && !can; i++){
        if(arr[i]!=i+1){
            for(j=i+1; j<n; j++){
                memcpy(tArr, arr, sizeof(arr));
                swap(arr[i], arr[j]);
                if(isSorted(arr, n)){
                    can=true;
                }
                swap(arr[i], arr[j]);
            }
        }
    }
    printf("%s\n", (can ? "YES" : "NO"));
    return 0;
}
