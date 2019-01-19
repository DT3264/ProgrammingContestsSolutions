#include<stdio.h>
char str[1000002];
int left, right;

int main (){
    int i;
    scanf("%s", str);
    for(i=0; str[i]; i++){
        if(str[i]=='('){
            left++;
        }
        else if(str[i]==')' && left-right>0){
            right++;
        }
    }
    printf("%d", right*2);
    return 0;
}
