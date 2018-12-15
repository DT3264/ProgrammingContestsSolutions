#include<stdio.h>

int main(){
    int n, i, m;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &m);
        int mov=0;
        while(m>=6){
            m-=6;
            mov++;
        }
        while(m>=5){
            m-=5;
            mov++;
        }
        while(m>=4){
            m-=4;
            mov++;
        }
        while(m>=3){
            m-=3;
            mov++;
        }
        while(m>=2){
            m-=2;
            mov++;
        }
        while(m>=1){
            m-=1;
            mov++;
        }
        printf("%d\n", mov);
    }
    return 0;
}