#include<stdio.h>
int main(){
    int n, i, t, maxN=0, minN=0, amazing=0;
    scanf("%d", &n);
    scanf("%d", &t);
    maxN=minN=t;
    for(i=1; i<n; i++){
        scanf("%d", &t);
        if(t>maxN){
            maxN=t;
            amazing++;
        }
        else if(t<minN){
            minN=t;
            amazing++;
        }
    }
    printf("%d", amazing);
    return 0;
}
