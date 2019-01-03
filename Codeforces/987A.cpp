#include<stdio.h>
#include<string.h>
bool power, time, space, soul, reality, mind;
int main(){
    int n, i;
    int totalGems=6;
    char str[20];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", str);
        if(strcmp(str, "purple")==0){
            power=true;
            totalGems--;
        }
        if(strcmp(str, "green")==0){
            time=true;
            totalGems--;
        }
        if(strcmp(str, "blue")==0){
            space=true;
            totalGems--;
        }
        if(strcmp(str, "orange")==0){
            soul=true;
            totalGems--;
        }
        if(strcmp(str, "red")==0){
            reality=true;
            totalGems--;
        }
        if(strcmp(str, "yellow")==0){
            mind=true;
            totalGems--;
        }
    }
    printf("%d\n", totalGems);
    if(!power){
        printf("Power\n");
    }
    if(!time){
        printf("Time\n");
    }
    if(!space){
        printf("Space\n");
    }
    if(!soul){
        printf("Soul\n");
    }
    if(!reality){
        printf("Reality\n");
    }
    if(!mind){
        printf("Mind\n");
    }
}
