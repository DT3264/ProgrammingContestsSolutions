#include<stdio.h>
int n;
char str[102], tmpStr[102];

void reverseStr(int x){
    int i;
    for(i=0; i<x; i++){
        tmpStr[i]=str[i];
    }
    int left=0;
    for(i=x-1; i>=0; i--){
        str[left++]=tmpStr[i];
    }
}

int main(){
    int i;
    scanf("%d %s", &n, str);
    for(i=2; i<=n; i++){
        if(n%i==0){
            reverseStr(i);
        }
    }
    printf("%s", str);
    return 0;
}
