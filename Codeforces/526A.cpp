#include<stdio.h>
#include<string.h>
char level[101];
int main(){
    int levelLen;
    int i, j, k, jumps;
    bool canJump=false;
    scanf("%d %s", &levelLen, level);
    for(i=1; i<=25 && !canJump; i++){
        for(j=0; j<levelLen && !canJump; j++){
            jumps=0;
            ///printf("start at %d\n", j);
            for(k=j; k<levelLen; k+=i){
                if(level[k]=='*'){
                    ///printf("jump at %d\n", k);
                    jumps++;
                }
                else break;
            }
            if(jumps==5) canJump = true;
        }
    }
    printf(canJump ? "yes" : "no");
    return 0;
}
