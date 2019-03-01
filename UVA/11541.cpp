#include<stdio.h>
#include<string.h>
char str[201];
int strLen;
int main(){
    int cases, contCases=1;
    char actualChar, charPos;
    int powerOf10=1;
    int lastIntPos;
    int totalChars=0;
    int i, j;
    scanf("%d", &cases);
    while(cases--){
        scanf("%s", str);
        strLen=strlen(str);
        printf("Case %d: ", contCases++);
        for(i=0; i<strLen; i++){
            if(str[i]>='A'){
                actualChar=str[i];
                charPos=i;
                powerOf10=1;
                totalChars=0;
                for(j=i+1; str[j]<'A' && j<strLen; j++){
                    lastIntPos=j;
                }
                for(j=lastIntPos; j>charPos; j--){
                    totalChars+=(str[j]-'0')*powerOf10;
                    powerOf10*=10;
                }
                for(j=0; j<totalChars; j++){
                    printf("%c", actualChar);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
