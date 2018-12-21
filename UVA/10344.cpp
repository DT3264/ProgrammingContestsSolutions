#include<stdio.h>
int arr[5];
bool used[5];
bool can23;
void calcula(int n, int posAcual, int step){
    ///printf("%d\n", posAcual);
    if(step==5){
        if(n==23) can23=true;
        return;
    }
    used[posAcual]=true;
    for(int i=posAcual; i<posAcual+5; i++){
        if(!used[i%5]){
            used[i%5]=true;
            calcula(n+arr[i%5], i%5, step+1);
            calcula(n-arr[i%5], i%5, step+1);
            calcula(n*arr[i%5], i%5, step+1);
            used[i%5]=false;
        }
    }
    used[posAcual]=false;
}
int main(){
    int i;
    while(scanf("%d", &arr[0])){
        for(i=1; i<5; i++){
            scanf("%d", &arr[i]);
        }
        if(arr[0]==0 &&
           arr[1]==0 &&
           arr[2]==0 &&
           arr[3]==0 &&
           arr[4]==0) break;
        can23=false;
        for(i=0; i<5; i++){
            calcula(arr[i], i, 1);
        }
        printf(can23? "Possible\n" : "Impossible\n");
    }
    return 0;
}
