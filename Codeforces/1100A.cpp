#include<stdio.h>
int n, k;
int study;
int social;
int arr[110];
int absN(int x){
    return (x>=0 ? x : x*-1);
}
int main(){
    int i, j;
    scanf("%d%d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i]==1){
            study++;
        }
        else{
            social++;
        }
    }
    int ans=-10000;
    for(i=0; i<k; i++){
        int tmpAns, tmpSocial=social, tmpStudy=study;
        for(j=i; j<n; j+=k){
            if(arr[j]==1){
                tmpStudy--;
            }
            else{
                tmpSocial--;
            }
        }
        tmpAns=absN(tmpStudy-tmpSocial);
        ans=(tmpAns>ans ? tmpAns : ans);
    }
    printf("%d", ans);
    return 0;
}

