#include<stdio.h>
int main(){
    int total=0 , t, i;
    for(i=0; i<5; i++){
        scanf("%d", &t);
        total+=t;
    }
    printf("%d\n", total%5 == 0 && total!=0 ? total/5 : -1);
    return 0;
}
