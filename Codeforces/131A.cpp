#include<stdio.h>
#include<string.h>
int main(){
    char str[101];
    scanf("%s", str);
    int strLen = strlen(str);
    int upC=0;
    for(int i=0; i<strLen; i++){
        if(str[i]>='A' && str[i]<='Z') upC++;
    }
    if(upC == strLen-1 && str[0]>='a' && str[0]<='z'){
        if(str[0]>='a' && str[0]<='z') printf("%c", str[0]-32);
        else printf("%c", str[0]);
        for(int i=1; i<strLen; i++){
            printf("%c", str[i]+32);
        }
    }
    else if(upC == strLen){
        for(int i=0; i<strLen; i++){
            printf("%c", str[i]+32);
        }
    }
    else{
        for(int i=0; i<strLen; i++){
            printf("%c", str[i]);
        }
    }
    return 0;
}
