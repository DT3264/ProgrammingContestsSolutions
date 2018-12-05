#include<stdio.h>
#include<string.h>
int main(){
    char str[101];
    scanf("%s", str);
    int strLen = strlen(str);
    bool nextShouldBeVowel=false;
    bool valid = true;
    if(str[0]!='a' && str[0]!='e' && str[0]!='i' && str[0]!='o' && str[0]!='u' && str[0]!='n') nextShouldBeVowel=true;
    for(int i=1; i<strLen && valid; i++){
        if(nextShouldBeVowel){
            if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u'){
                valid = false;
            }
            else nextShouldBeVowel = false;
        }
        else if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u' && str[i]!='n') nextShouldBeVowel=true;
    }
    printf(valid && !nextShouldBeVowel ? "YES" : "NO");
    return 0;
}
