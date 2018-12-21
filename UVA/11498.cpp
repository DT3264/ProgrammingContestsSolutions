#include <stdio.h>
using namespace std;

int main(){
    int k, i;
    while(scanf("%d", &k) && k!=0){
        int mainX, mainY, tempX, tempY;
        scanf("%d %d", &mainX, &mainY);
        for(i=0; i<k; i++){
            scanf("%d %d", &tempX, &tempY);
            if(tempX==mainX || tempY==mainY) printf("divisa\n");
            else if(tempX>mainX && tempY>mainY) printf("NE\n");
            else if(tempX<mainX && tempY<mainY) printf("SO\n");
            else if(tempX>mainX && tempY<mainY) printf("SE\n");
            else if(tempX<mainX && tempY>mainY) printf("NO\n");
        }
    }
    return 0;
}
