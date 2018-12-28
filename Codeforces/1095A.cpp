#include<stdio.h>
#include<string.h>
char enc[58];
int main(){
    int n, i, leng=1;
    scanf("%d%s", &n, enc);
    for(i=0; enc[i]; i+=leng){
        printf("%c", enc[i]);
        leng++;
    }
    return 0;
}
