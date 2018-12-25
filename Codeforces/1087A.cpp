#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    scanf("%s", str);
    int strLen = strlen(str)-1;
    printf("%c", str[strLen/2]);
    int start = (strLen/2)-1;
    int finish = (strLen/2)+1;
    while(start>=0 && finish<=strLen-1){
        printf("%c", str[finish++]);
        printf("%c", str[start--]);
        //printf("g");
    }
    if(finish==strLen){
        printf("%c", str[finish]);
    }
    if(start==0){
        printf("%c", str[start]);
    }
    return 0;
}