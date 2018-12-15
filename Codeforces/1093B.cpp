///Since a palindrome is read exactly from right lo left and vice versa
///at the first match of chars in the same position
///with an only swith of any other letter at any other position the palindrome gets invalidated
///but if there's no any other letter to switch, then the palindrome cannot be invalidated
///the only exceptional case is individual letters since an individual is a palindrome
#include<stdio.h>
#include<string.h>
char str[10000];
int strLen;

int switchAt(int x){
    for(int i=0; i<strLen; i++){
        if(str[i]!=str[x]){
            return i;
        }
    }
    return -1;
}
int main(){
    int n, i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", str);
        strLen = strlen(str);
        bool isPalindrome=false;
        for(j=0; j<strLen; j++){
            if(j==strLen-1-j){
                continue;
            }
            if(str[j]==str[strLen-1-j]){
                int newIndex = switchAt(j);
                if(newIndex==-1){
                    isPalindrome=true;
                }
                else{
                    char temp = str[newIndex];
                    str[newIndex]=str[j];
                    str[j]=temp;
                    j=strLen;
                }
            }
        }
        if(isPalindrome || strLen==1){
            printf("-1\n");
        }
        else{
            printf("%s\n", str);
        }
    }
    return 0;
}
