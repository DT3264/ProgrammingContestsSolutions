#include<stdio.h>
int main(){
    char str[5];
    scanf("%s", str);
    bool isGood=true;
    for(int i=1; i<4; i++){
        if(str[i]==str[i-1]){
            isGood=false;
        }
    }
    printf("%s\n", (isGood ? "Good" : "Bad"));
    return 0;
}
