#include<stdio.h>
#include<string.h>
int n, i, cont;
char str[1000];
int main (){
    scanf("%d", &n);
    scanf("%s", str);
    for(i=0; i<n-1; i++){
        if(str[i]==str[i+1]) cont++;
    }
    printf("%d", cont);
    return 0;
}
