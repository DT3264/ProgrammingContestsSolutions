#include<stdio.h>

char mapa[150][150];
int boom[150][150];
int n, m;

void kpow(int x, int y){
    for(int i=0; i<n; i++){
        if(i!=x)
        boom[i][y]++;
    }
    for(int i=0; i<m; i++){
        if(i!=y)
        boom[x][i]++;
    }
}

int tryPos1(int x, int y){
    int i, j;
    int astFound=0;
    for(i=0; i<n; i++){
        if(mapa[i][y]=='*'){
            astFound++;
            ///printf("foudn at %d %d with %d\n", i, y, astFound);
        }
    }
    if(astFound==2) return 1;
    for(j=0; j<m; j++){
        if(mapa[x][j]=='*'){
            astFound++;
            ///printf("foudn at %d %d with %d\n", x, j, astFound);
        }
    }
    return astFound;
}

int tryPos2(int x, int y){
    int i, j;
    int astFound=0;
    for(j=0; j<m; j++){
        if(mapa[x][j]=='*'){
            astFound++;
            ///printf("foudn at %d %d with %d\n", x, j, astFound);
        }
    }
    if(astFound==2) return 1;
    for(i=0; i<n; i++){
        if(mapa[i][y]=='*'){
            astFound++;
            ///printf("foudn at %d %d with %d\n", i, y, astFound);
        }
    }

    return astFound;
}

int main(){
    int i, j;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf(" %c", &mapa[i][j]);
            if(mapa[i][j]=='*'){
                kpow(i, j);
            }
        }
    }
    bool found=false;
    for(i=0; i<n && !found; i++){
        for(j=0; j<m && !found; j++){
            ///printf("looking in %d %d\n", i, j);
            if(boom[i][j]==2 && mapa[i][j]!='*'){
                if(tryPos1(i, j)==2 && tryPos2(i, j)==2) printf("%d %d\n", i+1, j+1);
            }
        }
    }
    return 0;
}
