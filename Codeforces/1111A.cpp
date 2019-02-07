#include<stdio.h>
#include<string.h>
char str1[1002];
char str2[1002];
int i, c1, v1, c2, v2;
bool isVowel(char c){
    return (c=='a' ||
           c=='e' ||
           c=='i' ||
           c=='o' ||
           c=='u');
}
int main (){
    scanf("%s", str1);
    scanf("%s", str2);
    int strLen1=strlen(str1);
    int strLen2=strlen(str2);
    if(strLen1!=strLen2){
        printf("No");
        return 0;
    }
    for(i=0; i<strLen1; i++){
        if(isVowel(str1[i]) && !isVowel(str2[i])){
            printf("No");
            return 0;
        }
        if(!isVowel(str1[i]) && isVowel(str2[i])){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
