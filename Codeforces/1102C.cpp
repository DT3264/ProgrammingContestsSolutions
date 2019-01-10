#include<stdio.h>
#include<algorithm>
int n, x, y, cont;
int arr[101];
int main(){
    int i;
    scanf("%d%d%d", &n, &x, &y);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr+n);
    bool policeTurn=true;
    if(x>y){
        ///We asume he can destroy all at some moment
        cont=n;
    }
    else{
        for(i=0; i<n; i++){
            if(policeTurn){
                arr[i]-=x;
                if(arr[i]<=0){
                    cont++;
                }
            }
            else{
                arr[i]+=y;
            }
            policeTurn=!policeTurn;
        }
    }
    printf("%d", cont);
    return 0;
}

