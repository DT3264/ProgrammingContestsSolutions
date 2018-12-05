#include<stdio.h>

int maxPlay=0;

void play(int p1, int p2, int cont){
    if(p1<=0 || p2<=0){
        if(cont>maxPlay && p1>=0 && p2>=0) maxPlay=cont;
        return;
    }
    if(p1<=p2) play(p1+1, p2-2, cont+1);
    else       play(p1-2, p2+1, cont+1);
}

int main(){
    int p1, p2;
    scanf("%d %d", &p1, &p2);
    play(p1, p2, 0);
    printf("%d", maxPlay);
    return 0;
}
