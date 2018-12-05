#include<stdio.h>
int h1, a1, c1;
int h2, a2;
int totalTimes=0, i;
void play(bool print){
    while(h2>0){
        ///his atack will kill you -> drink a cure
        if(h1-a2<=0){
            if(h2-a1<=0){
                h2-=a1;
                printf(print ? "STRIKE\n" : "");
            }
            else{
                h1+=c1;
                printf(print ? "HEAL\n" : "");
            }
        }
        ///Kill him!
        else{
            h2-=a1;
            printf(print ? "STRIKE\n" : "");
        }
        totalTimes++;
        h1-=a2;
    }
}

int main(){
    int bkh1, bkh2;
    scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);
    bkh1 = h1, bkh2 = h2;
    play(false);
    printf("%d\n", totalTimes);
    totalTimes=0;
    h1 = bkh1, h2 = bkh2;
    play(true);
    return 0;
}
