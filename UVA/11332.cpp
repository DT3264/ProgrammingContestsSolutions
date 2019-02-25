#include<stdio.h>
#include<string.h>
char str[15];
int main(){
    int i, strPos;
    int total, tmpTotal;
    while(scanf("%s", str) && strcmp(str, "0")!=0){
        i=0;
        do{
            total=0;
            for(i=0; str[i]; i++){
                total+=str[i]-'0';
            }
            strPos=0;
            memset(str, 0, sizeof(str));
            tmpTotal=total;
            while(tmpTotal>0){
                str[strPos++]=(tmpTotal%10)+'0';
                tmpTotal/=10;
            }
        }
        while(total>9);
        printf("%d\n", total);
    }
    return 0;
}
