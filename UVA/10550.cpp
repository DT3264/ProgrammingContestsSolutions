#include<iostream>

int main(){
    int actualPos, a1, a2, a3;
    int actualDegrees;
    while(scanf("%d%d%d%d", &actualPos, &a1, &a2, &a3) && actualPos+a1+a2+a3!=0){
        actualDegrees=0;
        actualDegrees+=360*2;
        while(actualPos!=a1){
            actualPos--;
            if(actualPos==-1){
                actualPos=39;
            }
            actualDegrees+=9;
        }
        actualDegrees+=360;
        while(actualPos!=a2){
            actualPos++;
            if(actualPos==40){
                actualPos=0;
            }
            actualDegrees+=9;
        }
        while(actualPos!=a3){
            actualPos--;
            if(actualPos==-1){
                actualPos=39;
            }
            actualDegrees+=9;
        }
        printf("%d\n", actualDegrees);
    }
    return 0;
}

