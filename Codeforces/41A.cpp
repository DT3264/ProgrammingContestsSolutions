#include<stdio.h>
#include<string.h>
int main(){
    char str1[101], str2[101];
    scanf("%s %s", str1, str2);
    bool correct = true;
    int strLen = strlen(str1), i, pos2 = strLen-1;
    for(i=0; i<strLen && correct; i++){
        if(str1[i]!=str2[pos2--]) correct=false;
    }
    printf(correct ? "YES" : "NO");
    return 0;
}
