#include<stdio.h>
#include<string.h>
char str[1000000];
int strLen;
int toDel;
bool canBeMade=true;
int beginIndex=-1, endIndex=-1;
int firstColon=-1, lastColon=-1;

int findStart(){
    for(int i=0; i<strLen; i++){
        if(str[i]=='['){
            return i;
        }
    }
    return -1;
}
int findEnd(){
    for(int i=strLen-1; i>beginIndex; i--){
        if(str[i]==']'){
            return i;
        }
    }
    return -1;
}
int findFirstColon(){
    for(int i=beginIndex+1; i<endIndex; i++){
        if(str[i]==':'){
            return i;
        }
    }
    return -1;
}

int findLastColon(){
    for(int i=endIndex-1; i>beginIndex; i--){
        if(str[i]==':'){
            return i;
        }
    }
}

void invalidate(){
    canBeMade=false;
}

int main(){
    scanf("%s", str);
    strLen=strlen(str);
    int i;
    beginIndex=findStart();
    if(beginIndex==-1){
        invalidate();
    }
    if(canBeMade){
        endIndex=findEnd();
    }
    if(endIndex==-1){
        invalidate();
    }
    if(canBeMade){
        firstColon=findFirstColon();
    }
    if(firstColon==-1){
        invalidate();
    }
    if(canBeMade){
        lastColon=findLastColon();
    }
    if(lastColon==-1 || firstColon==lastColon){
        invalidate();
    }
    if(canBeMade){
        for(i=0; i<beginIndex; i++){
            toDel++;
        }
        for(i=beginIndex+1; i<firstColon; i++){
            toDel++;

        }
        for(i=firstColon+1; i<lastColon; i++){
            if(str[i]!='|'){
                toDel++;
            }
        }
        for(i=lastColon+1; i<endIndex; i++){
            toDel++;
        }
        for(i=endIndex+1; i<strLen; i++){
            toDel++;
        }
        printf("%d", strLen-toDel);
    }
    else{
        printf("-1");
    }
    return 0;
}

