#include<stdio.h>
int main (){
    int n, c, i, actualN, lastN, cont=1;
    scanf("%d%d", &n, &c);
    scanf("%d", &lastN);
    for(i=1; i<n; i++){
        scanf("%d", &actualN);
        if(actualN-lastN<=c){
            cont++;
        }
        else{
            cont=1;
        }
        lastN=actualN;
    }
    printf("%d", cont);
    return 0;
}
