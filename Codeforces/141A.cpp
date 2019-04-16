#include<stdio.h>
int letters[26];
char str1[101], str2[101], finalStr[101];
int main(){
    scanf("%s %s %s", str1, str2, finalStr);
    int i;
    bool ans=true;
    for(i=0; str1[i]; i++){
        letters[str1[i]-'A']++;
    }
    for(i=0; str2[i]; i++){
        letters[str2[i]-'A']++;
    }
    for(i=0; finalStr[i]; i++){
        letters[finalStr[i]-'A']--;
    }
    for(i=0; i<27; i++){
        if(letters[i]!=0){
            ans=false;
        }
    }
    printf("%s", (ans ? "YES" : "NO"));
}
