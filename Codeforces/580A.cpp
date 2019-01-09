#include<stdio.h>
int i, n, ans, actualAns=1;
int main(){
    int lastN, actualN;
    scanf("%d%d", &n, &lastN);
    for(i=1; i<n; i++){
        scanf("%d", &actualN);
        if(actualN>=lastN){
            actualAns++;
        }
        else{
            if(actualAns>ans){
                ans=actualAns;
            }
            actualAns=1;
        }
        lastN=actualN;
    }
    if(actualAns>ans){
        ans=actualAns;
    }
    printf("%d", ans);
    return 0;
}
