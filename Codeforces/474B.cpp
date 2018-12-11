#include<stdio.h>
#include<vector>
int n, m, i, arr[100000];
int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(i>0) arr[i]+=arr[i-1];
    }
    int q;
    scanf("%d", &m);
    for(i=0; i<m; i++){
        scanf("%d", &q);
        //printf("looking for n>=%d\n", q);
        int left=0, right=n-1;
        int mid;
        int lastGuess=-1;
        while(left<=right){
            mid=left+(right-left+1)/2;
            //printf("actualGuess %d -> %d\n", mid, arr[mid]);
            if(arr[mid]>q){
                lastGuess=mid;
                right=mid-1;
            }
            else if(arr[mid]==q){
                lastGuess=mid;
                break;
            }
            else left=mid+1;
        }
        printf("%d\n", lastGuess+1);
    }
    return 0;
}
