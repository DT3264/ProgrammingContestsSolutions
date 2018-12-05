#include<stdio.h>
#include<string.h>
char num[10000000];
int main(){
    scanf("%s", num);
    long long strLen = strlen(num);
    long long total=0;
    long long contSpell=0;
    while(strLen>1){
        for(int i=0; i<strLen; i++){
            ///printf("%d ", num[i]-'0');
            total+=num[i]-'0';
        }
        ///printf("\n%d", total);
        strLen = 0;
        while(total>0){
            num[strLen++]=(total%10)+'0';
            total/=10;
        }
        contSpell++;
    }
    printf("%lld", contSpell);
}
