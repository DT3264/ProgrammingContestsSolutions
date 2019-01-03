#include<stdio.h>
char str[101];
int n, m, i, j;
int a, b; 
char t1, t2;
int main(){
    scanf("%d%d %s", &n, &m, str);
    for(i=0; i<m; i++){
        scanf("%d%d %c %c", &a, &b, &t1, &t2);
        for(j=a-1; j<=b-1; j++){
            if(str[j]==t1){
                str[j]=t2;
            }
        }
    }
    printf("%s", str);

}
