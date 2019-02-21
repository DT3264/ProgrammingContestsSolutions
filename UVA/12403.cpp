#include<stdio.h>
#include<string.h>
int n, i, total, donation;
char op[7];
int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", op);
        if(strcmp(op, "report")==0){
            printf("%d\n", total);
        }
        else{
            scanf("%d", &donation);
            total+=donation;
        }
    }
    return 0;
}

