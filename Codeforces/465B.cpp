#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int t, contMov=0, i, arr[1001];
    bool startCount=false;
    for(i=0; i<n; i++){
        scanf("%d", &t);
        if(t==1){
            startCount=true;
            contMov++;
        }
        if(t==0 && startCount){
            contMov++;
            startCount=false;
        }
    }
    if(!startCount) contMov--;
    if(contMov<0) contMov=0;
    printf("%d", contMov);
    return 0;

}
