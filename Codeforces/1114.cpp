#include<stdio.h>
int main(){
    int a1, b1, c1;
    int a2, b2, c2;
    scanf("%d%d%d", &a1, &b1, &c1);
    scanf("%d%d%d", &a2, &b2, &c2);
    while(a1>0 && a2>0){
        a1--, a2--;
    }
    //printf("%d %d %d\n%d %d %d\n\n", a1, b1, c1, a2, b2, c2);
    while(b1>0 && (a2>0 || b2>0)){
        b1--;
        if(a2>0){
            a2--;
        }
        else{
            b2--;
        }
    }
    //printf("%d %d %d\n%d %d %d\n\n", a1, b1, c1, a2, b2, c2);
    while(c1>0 && (a2>0 || b2>0 || c2>0)){
        c1--;
        if(a2>0){
            a2--;
        }
        else if(b2>0){
            b2--;
        }
        else{
            c2--;
        }
    }
    //printf("%d %d %d\n%d %d %d\n\n", a1, b1, c1, a2, b2, c2);
    if(a1==b1 && b1==c1 && c1==0){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
