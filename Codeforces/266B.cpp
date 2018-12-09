#include<stdio.h>

using namespace std;

char guys[51];
int cant, time, i;

int main(){
    scanf("%d %d", &cant, &time);
    scanf("%s", guys);
    while(time>0){
        for(i=cant-1; i>0; i--){
            if(guys[i]=='G' && guys[i-1]=='B'){
                guys[i]='B';
                guys[i-1]='G';
                i--;
            }
        }
        time--;
    }
    for(i=0; i<cant; i++){
        printf("%c", guys[i]);
    }
    return 0;
}
