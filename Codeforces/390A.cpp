#include<stdio.h>
bool bukX[110], bukY[110];
int contX, contY;

int main(){
    int n, i, x, y;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d", &x, &y);
        if(!bukX[x]){
            bukX[x]=1;
            contX++;
        }
        if(!bukY[y]){
            bukY[y]=1;
            contY++;
        }
    }
    printf("%d", contX<=contY ? contX : contY);
    return 0;
}
