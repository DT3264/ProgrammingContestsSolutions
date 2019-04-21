#include<stdio.h>
#include<algorithm>
int arr[200001];
int n, b, a;
int ans;
int main(){
    scanf("%d%d%d", &n, &b, &a);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int aN=-1, aB=b, aA=a;
    while(aN<n && (aB>0 || aA>0)){
        //printf("%sB: %d, A: %d, P: %d\n", (arr[aN]==1 ? "*" : ""), aB, aA, aN);
        if(arr[aN+1]==1 && aA<a){
            if(aB>0){
                aB--;
                aA++;
            }
            else{
                aA--;
            }
        }
        else{
            if(aA>0){
                aA--;
            }
            else{
                aB--;
            }
        }
        aN++;
    }
    //printf("%sB: %d, A: %d, P: %d\n", (arr[aN]==1 ? "*" : ""), aB, aA, aN);
    printf("%d", (aN+1<=n ? aN+1 : n));
    return 0;
}
