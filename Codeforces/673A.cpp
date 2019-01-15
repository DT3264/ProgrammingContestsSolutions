#include<stdio.h>
int arr[100];
bool ended=false;
int main (){
    int n, i, t, res=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        if(t-res<=15){
            res=t;
        }
        else{
            res+=15;
            ended=true;
            break;
        }
    }
    res+=(ended ? 0 : 15);
    res=(res>90 ? 90 : res);
    printf("%d", res);
    return 0;
}
