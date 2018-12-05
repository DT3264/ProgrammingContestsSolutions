#include<stdio.h>
#include<string.h>
char str[1000];
int minDist(char a, char b){
    char tempA=a;
    int cont1=0, cont2=0;
    while(tempA!=b){
        tempA++;
        cont1++;
        if(tempA=='z'+1) tempA='a';
    }
    tempA=a;
    while(tempA!=b){
        tempA--;
        cont2++;
        if(tempA=='a'-1) tempA='z';
    }
    return cont1<=cont2?cont1:cont2;
}
int main (){
    int i, strLen, total=0;
    scanf("%s", str);
    char lastC='a';
    strLen = strlen(str);
    for(i=0; i<strLen; i++){
        total+=minDist(lastC, str[i]);
        lastC=str[i];
    }
    printf("%d", total);
    return 0;
}
