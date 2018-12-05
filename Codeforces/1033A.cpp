#include<stdio.h>
#include<queue>
using namespace std;
int n;
int qX, qY, kX, kY, destX, destY;
char board[1001][1001];

struct actualPos{
    int x;
    int y;
};

queue<actualPos> kingPositions;

void expandQueen(int x, int y){
    int i;
    for(i=0; i<n; i++) board[x][i]='*';
    for(i=0; i<n; i++) board[i][y]='*';
    int j1=y, j2=y;
    for(i=x; i>=0; i--){
        if(j1-1>=0)
            board[i][j1--]='*';
        if(j2+1<n)
            board[i][j2++]='*';
    }
    j1=y, j2=y;
    for(i=x; i<n; i++){
        if(j1-1>=0)
            board[i][j1--]='*';
        if(j2+1<n)
            board[i][j2++]='*';
    }
}

void moveKing(){
    actualPos currentKPos;
    actualPos newPos;
    int x, y;
    while(!kingPositions.empty()){
        currentKPos = kingPositions.front();
        kingPositions.pop();
        x = currentKPos.x, y = currentKPos.y;
        if(x>=0 && x<n && y>=0 && y<n){
            if(board[x][y] != '*' && board[x][y] != '.'){
                board[x][y]='.';
                if(x == destX && y == destY) return;
                ///
                newPos.x = x-1, newPos.y = y-1;
                    kingPositions.push(newPos);
                newPos.x = x-1, newPos.y = y;
                    kingPositions.push(newPos);
                newPos.x = x-1, newPos.y = y+1;
                    kingPositions.push(newPos);
                ///
                newPos.x = x, newPos.y = y-1;
                    kingPositions.push(newPos);
                newPos.x = x, newPos.y = y+1;
                    kingPositions.push(newPos);
                ///
                newPos.x = x+1, newPos.y = y-1;
                        kingPositions.push(newPos);
                newPos.x = x+1, newPos.y = y;
                        kingPositions.push(newPos);
                newPos.x = x+1, newPos.y = y+1;
                    kingPositions.push(newPos);

            }
        }
    }
}

void printChess(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int i, j;
    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &qX, &qY, &kX, &kY, &destX, &destY);
    qX--, qY--, kX--, kY--, destX--, destY--;
    expandQueen(qX, qY);
    actualPos firstPos;
    firstPos.x = kX, firstPos.y = kY;
    kingPositions.push(firstPos);
    moveKing();
    ///printChess();
    printf("%s", board[destX][destY]=='.' ? "YES" : "NO");
    return 0;
}
