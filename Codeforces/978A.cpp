#include<stdio.h>
int buk[10001];
int arr[51];
bool toUse[51];
int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int cont=0;
    for(i=n-1; i>=0; i--){
        if(buk[arr[i]]==0){
            buk[arr[i]]++;
            toUse[i]=1;
            cont++;
        }
    }
    printf("%d\n", cont);
    for(i=0; i<n; i++){
        if(toUse[i]) printf("%d ", arr[i]);
    }
    return 0;
}



