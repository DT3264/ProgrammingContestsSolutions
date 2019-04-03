#include<stdio.h>
#include<string.h>
int main(){
    char str[1000000];
    int strLen;
    scanf("%s", str);
    strLen=strlen(str);
    for(int i=0; i<strLen; i++){
        if(str[i]=='.'){
            printf("0");
        }
        if(i+1<strLen){
            if(str[i]=='-'){
                if(str[i+1]=='.'){
                    printf("1");
                }
                else if(str[i+1]=='-'){
                    printf("2");
                }
                i++;
            }
        }
    }
}
