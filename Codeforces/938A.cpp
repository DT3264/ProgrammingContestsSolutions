#include<stdio.h>
char str[100];
int n, i;

bool isVow(char chr){
    return chr=='a' ||
           chr=='e' ||
           chr=='i' ||
           chr=='y' ||
           chr=='o' ||
           chr=='u';
}

void delChar(int i){
    for(i=i; i<n; i++){
        str[i]=str[i+1];
    }
    n--;
}

int main(){
    bool lastWasVowel=false;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf(" %c", &str[i]);
    }
    for(i=0; i<n-1; i++){
        if(isVow(str[i])){
            while(isVow(str[i+1])){
                delChar(i+1);
            }
        }
    }
    printf("%s", str);
    return 0;
}
