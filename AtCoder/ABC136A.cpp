#include <stdio.h>
int main(){
    int a, b, c;
    int toDel;
    scanf("%d%d%d", &a, &b, &c);
    a-=b;
    if(a<0) a*=-1;
    c-=a;
    if(c<0){
        c=0;
    }
    printf("%d\n", c);
    return 0;
}
