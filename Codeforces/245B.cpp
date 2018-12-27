#include<stdio.h>
#include<string.h>
char link[51];
int actualPos=0;
int main(){
    scanf("%s", link);
    int strLen = strlen(link);
    if(link[0]=='h'){
        printf("http://");
        actualPos=4;
    }
    else{
        printf("ftp://");
        actualPos=3;
    }
    for(actualPos=actualPos; actualPos<strLen; actualPos++){
        printf("%c", link[actualPos]);
        if(link[actualPos+1]=='r' && link[actualPos+2]=='u'){
            break;
        }
    }
    printf(".ru");
    actualPos+=3;
    if(actualPos<strLen){
        printf("/");
    }
    for(actualPos=actualPos; actualPos<strLen; actualPos++){
        printf("%c", link[actualPos]);
    }
    return 0;
}
