#include<bits/stdc++.h>
using namespace std;
bool inBounds(int i, int j){
    return i>=0 && i<8 && j>=0 && j<8;
}
char mapa[8][8];
int atack[8][8];
void atackDiagonals(int x, int y){
    int i, j;
    i=x+1, j=y+1;
    while(inBounds(i, j)){
        if(mapa[i][j]!='.') break;
        atack[i][j]=1;
        i++, j++;
    }
    i=x-1, j=y-1;
    while(inBounds(i, j)){
        if(mapa[i][j]!='.') break;
        atack[i][j]=1;
        i--, j--;
    }
    i=x+1, j=y-1;
    while(inBounds(i, j)){
        if(mapa[i][j]!='.') break;
        atack[i][j]=1;
        i++, j--;
    }
    i=x-1, j=y+1;
    while(inBounds(i, j)){
        if(mapa[i][j]!='.') break;
        atack[i][j]=1;
        i--, j++;
    }
}
void atackSides(int x, int y){
    for(int i=x+1; i<8; i++){
        if(inBounds(i, y)){
            if(mapa[i][y]!='.') break;
            atack[i][y]=1;
        }
    }
    for(int i=x-1; i>=0; i--){
        if(inBounds(i, y)){
            if(mapa[i][y]!='.') break;
            atack[i][y]=1;
        }
    }
    for(int i=y+1; i<8; i++){
        if(inBounds(i, y)){
            if(mapa[x][i]!='.') break;
            atack[x][i]=1;
        }
    }
    for(int i=y-1; i>=0; i--){
        if(inBounds(i, y)){
            if(mapa[x][i]!='.') break;
            atack[x][i]=1;
        }
    }
}
void atackKnight(int i, int j){
    for(int x=-1; x<=1; x+=2){
        if(inBounds(i+x, j-2)){
            atack[i+x][j-2]=1;
        }
    }
    for(int x=-1; x<=1; x+=2){
        if(inBounds(i+x, j+2)){
            atack[i+x][j+2]=1;
        }
    }
    for(int x=-1; x<=1; x+=2){
        if(inBounds(i-2, j+x)){
            atack[i-2][j+x]=1;
        }
    }
    for(int x=-1; x<=1; x+=2){
        if(inBounds(i+2, j+x)){
            atack[i+2][j+x]=1;
        }
    }
}
void atackKing(int i, int j){
    int nX, nY;
    nX=-1, nY=-1;
    if(inBounds(i+nX, j+nY)){
        atack[i+nX][j+nY]=1;
    }
    nX=-1, nY=0;
    if(inBounds(i+nX, j+nY)){
        atack[i+nX][j+nY]=1;
    }
    nX=1, nY=1;
    if(inBounds(i+nX, j+nY)){
        atack[i+nX][j+nY]=1;
    }
    nX=0, nY=-1;
    if(inBounds(i+nX, j+nY)){
        atack[i+nX][j+nY]=1;
    }
    nX=0, nY=1;
    if(inBounds(i+nX, j+nY)){
        atack[i+nX][j+nY]=1;
    }
    nX=1, nY=-1;
    if(inBounds(i+nX, j+nY)){
        atack[i+nX][j+nY]=1;
    }
    nX=1, nY=0;
    if(inBounds(i+nX, j+nY)){
        atack[i+nX][j+nY]=1;
    }
    nX=-1, nY=1;
    if(inBounds(i+nX, j+nY)){
        atack[i+nX][j+nY]=1;
    }
}
void atackPawn(int i, int j, int x){
    for(int y=-1; y<=1; y++){
        if(y==0) continue;
        if(inBounds(i+x, j+y)){
            atack[i+x][j+y]=true;
        }
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int firstCase=true;
    while(cin >> str){
        memset(atack, 0, sizeof(atack));
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                mapa[i][j]='.';
            }
        }
        int row=0;
        int col=0;
        for(char c : str){
            if(c>='1' && c<='8'){
                while(c>'0'){
                    col++;
                    c--;
                }
                continue;
            }
            if(c=='/'){
                row++;
                col=0;
                continue;
            }
            mapa[row][col]=c;
            atack[row][col]=1;
            col++;
        }
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(mapa[i][j]=='R' || mapa[i][j]=='r'){///Torre
                    atackSides(i, j);
                }
                if(mapa[i][j]=='N' || mapa[i][j]=='n'){///Caballo
                    atackKnight(i, j);
                }
                if(mapa[i][j]=='B' || mapa[i][j]=='b'){///Alfil
                    atackDiagonals(i, j);
                }
                if(mapa[i][j]=='K' || mapa[i][j]=='k'){///Rey
                    atackKing(i, j);
                }
                if(mapa[i][j]=='Q' || mapa[i][j]=='q'){///Reina
                    atackSides(i, j);
                    atackDiagonals(i, j);
                }
                if(mapa[i][j]=='P'){///Peón blanco // hacia arriba
                    atackPawn(i, j, -1);
                }
                if(mapa[i][j]=='p'){///Peon negro / Hacia abajo
                    atackPawn(i, j, 1);
                }
            }
        }
        int ans=0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(!atack[i][j]) ans++;
            }
        }
        cout << ans << endl;
    }
	return 0;
}
