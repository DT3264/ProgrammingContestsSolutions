#include<stdio.h>
#include<string.h>
int n, i, cont;
char str[1000];

bool isWub(int i){
    return str[i]=='W' && str[i+1]=='U' && str[i+2]=='B';
}

int main (){
    scanf("%s", str);
    int strLen = strlen(str);
    bool hasPrintElse=false, lastWasSpace;
    for(i=0; i<strLen; i++){
        if(isWub(i)){
           i+=2;
           if(hasPrintElse && !lastWasSpace) printf(" ");
            lastWasSpace=true;
        }
        else{
            printf("%c", str[i]);
            hasPrintElse=true;
            lastWasSpace=false;
        }

    }
    return 0;
}
