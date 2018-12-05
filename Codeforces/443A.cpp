#include<stdio.h>

bool buk[50];
int total;

int main (){
    char t;
    while(scanf("%c", &t) && t!='}'){
        if(t>='a' && t<='z'){
            if(!buk[t-'a']){
                buk[t-'a']=true;
                total++;
            }
        }
    }
    printf("%d", total);
    return 0;
}
