#include<stdio.h>
char mainCard[3];
char handCard[3];
bool canPlay;

int main(){
    int i;
    scanf("%s", mainCard);
    for(i=0; i<5; i++){
        scanf("%s", handCard);
        if(handCard[0]==mainCard[0] || handCard[1]==mainCard[1]){
            canPlay=true;
        }
    }
    printf("%s", (canPlay ? "YES" : "NO"));
}
