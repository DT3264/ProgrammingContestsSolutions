#include<stdio.h>
#include<string.h>
char str[6];
int actualCase=1;
int main(){
    while(scanf("%s", str) && strcmp(str, "*")!=0){
        if(strcmp(str, "Hajj")==0){
            printf("Case %d: Hajj-e-Akbar\n", actualCase++);
        }
        else{
            printf("Case %d: Hajj-e-Asghar\n", actualCase++);
        }
    }
    return 0;
}
