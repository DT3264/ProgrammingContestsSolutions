#include<stdio.h>
#include<string.h>

bool isVowel(char c){
    return  (c=='a' || c== 'e' || c== 'i' || c== 'o' || c== 'u');
}

int main(){
    int strLen, i, j;
    char str[102];
    int ans[3];
    memset(ans, 0, sizeof(ans));
    for(i=0; i<3; i++){
        gets(str);
        strLen=strlen(str);
        for(j=0; j<strLen; j++){
            if(isVowel(str[j])){
                ans[i]++;
            }
        }
        //printf("%d\n", ans[ansPos]);
    }
    printf("%s", (ans[0]==5 && ans[1]==7 && ans[2]==5 ? "YES" : "NO"));
    return 0;
}
