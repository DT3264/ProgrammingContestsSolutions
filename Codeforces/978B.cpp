#include<stdio.h>
#include<string.h>
char str[102];
int strLen, cont;
bool isX(int i){
    return str[i]=='x';
}

void moveTo(int i){
    for(i=i; i<strLen; i++){
        str[i]=str[i+1];
    }
    strLen--;
}

void chechWhole(){
    for(int i=0; i<strLen-2; i++){
        if(isX(i) && isX(i+1) && isX(i+2)){
            moveTo(i+2);
            cont++;
        }
    }
}

bool hasXX(){
    for(int i=0; i<strLen; i++){
        if(isX(i) && isX(i+1) && isX(i+2)) return true;
    }
    return false;
}

int main(){
    int i;
    scanf("%d%s", &i, str);
    strLen = strlen(str);
    while(hasXX()){
        chechWhole();
    }
    printf("%d", cont);
    return 0;
}



