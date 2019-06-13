#include <bits/stdc++.h>
using namespace std;
int n, m;
int cont;
char mapa[501][501];
struct pos{
    int x, y;
};
vector<pos>start;
int dX[4]={-1, 1, 0, 0};
int dY[4]={0, 0, -1, 1};
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void del(int x, int y){
    int tX=x-1, tY=y;
    while(isValid(tX, tY)){
        if(mapa[tX][tY]!='*'){
            break;
        }
        mapa[tX][tY]='.';
        tX--;
        cont--;
    }
    tX=x+1, tY=y;
    while(isValid(tX, tY)){
        if(mapa[tX][tY]!='*'){
            break;
        }
        mapa[tX][tY]='.';
        tX++;
        cont--;
    }
    tX=x, tY=y-1;
    while(isValid(tX, tY)){
        if(mapa[tX][tY]!='*'){
            break;
        }
        mapa[tX][tY]='.';
        tY--;
        cont--;
    }

    tX=x, tY=y+1;
    while(isValid(tX, tY)){
        if(mapa[tX][tY]!='*'){
            break;
        }
        mapa[tX][tY]='.';
        tY++;
        cont--;
    }
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, j, k, validPos;
    cin >> n >> m;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> mapa[i][j];
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(mapa[i][j]=='*'){
                cont++;
                //printf("on %d, %d\n", i, j);
                validPos=0;
                for(k=0; k<4; k++){
                    int nX=i+dX[k], nY=j+dY[k];
                    //printf("checking %d, %d \n", nX, nY);
                    if(isValid(nX, nY)){
                        if(mapa[nX][nY]=='*'){
                            validPos++;
                            //printf("valid pos: %d\n", validPos);
                        }
                    }
                }
            }
            if(validPos==4){
                start.push_back({i, j});
                //printf("start at %d, %d\n", i, j);
            }
        }
    }
    if(start.size()==1){
        cont--;
        del(start[0].x, start[0].y);
        if(cont>0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    else{
        printf("NO\n");
    }
}