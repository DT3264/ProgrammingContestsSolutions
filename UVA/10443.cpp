#include<bits/stdc++.h>
using namespace std;
int n, m;
int dX[4]={-1, 1, 0, 0};
int dY[4]={0, 0, -1, 1};
char board[101][101], newBoard[101][101];
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
bool hasNear(int x, int y, char toFind){
    int nX, nY;
    for(int i=0; i<4; i++){
        nX=x+dX[i];
        nY=y+dY[i];
        if(isValid(nX, nY) && board[nX][nY]==toFind){
            return true;
        }
    }
    return false;
}
void simulateDay(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='R' && hasNear(i, j, 'P')){
                newBoard[i][j]='P';
            }
            else if(board[i][j]=='S' && hasNear(i, j, 'R')){
                newBoard[i][j]='R';
            }
            else if(board[i][j]=='P' && hasNear(i, j, 'S')){
                newBoard[i][j]='S';
            }
            else{
                newBoard[i][j]=board[i][j];
            }
        }
    }
    memcpy(board, newBoard, sizeof(newBoard));
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases, actCase=1;
    int days;
    cin >> cases;
    while(cases--){
        if(actCase++>1) cout << "\n";
        cin >> n >> m >> days;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> board[i][j];
            }
        }
        while(days-->0){
            simulateDay();
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
