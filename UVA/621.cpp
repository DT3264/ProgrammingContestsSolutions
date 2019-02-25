#include<stdio.h>
#include<string.h>
int n, i;
int pos;
char str[100000];
char res;
int strLen;
int main(){
    scanf("%d", &n);
    while(n--){
        res=0;
        scanf("%s", str);
        strLen = strlen(str);
        if(strcmp(str, "1")==0  || strcmp(str, "4")==0 || strcmp(str, "78")==0 ){
            res='+';
        }
        else if(str[strLen-2]=='3'&& str[strLen-1]=='5'){
            res='-';
        }
        else if(str[0]=='9'&& str[strLen-1]=='4'){
            res='*';
        }
        else if(str[0]=='1'&& str[1]=='9' && str[2]=='0'){
            res='?';
        }
        printf("%c\n", res);
    }
    return 0;
}
