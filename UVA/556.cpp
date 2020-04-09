#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<string> mapa;
vector<vector<int>> mark;
struct Pii{
    int x;
    int y;
};
Pii pos;
int actualOrientation=1;///0=U,1=R,2=D,3=L
bool posInBounds(Pii newPos){
    return newPos.x>=0 && newPos.x<n && newPos.y>=0 && newPos.y<m;
}
Pii getPos(int orientation){
    if(orientation==0){
        ///x-1
        return {pos.x-1, pos.y};
    }
    else if(orientation==1){
        ///y+1
        return {pos.x, pos.y+1};
    }
    else if(orientation==2){
        ///x+1
        return {pos.x+1, pos.y};
    }
    else{
        ///y-1
        return {pos.x, pos.y-1};
    }
}
void turnRight(){
    actualOrientation++;
    if(actualOrientation==4) actualOrientation=0;
}
void turnLeft(){
    actualOrientation--;
    if(actualOrientation==-1) actualOrientation=3;
}
bool frontIsClear(){
    Pii frontPos;
    if(actualOrientation==0){
        ///x-1
        frontPos=getPos(0);
    }
    if(actualOrientation==1){
        ///y+1
        frontPos=getPos(1);
    }
    if(actualOrientation==2){
        ///x+1
        frontPos=getPos(2);
    }
    if(actualOrientation==3){
        ///y-1
        frontPos=getPos(3);
    }
    if(posInBounds(frontPos)){
        return mapa[frontPos.x][frontPos.y]=='0';
    }
    return false;
}
bool rightIsClear(){
    Pii newPos;
    if(actualOrientation==0){
        newPos=getPos(1);
    }
    if(actualOrientation==1){
        newPos=getPos(2);
    }
    if(actualOrientation==2){
        newPos=getPos(3);
    }
    if(actualOrientation==3){
        newPos=getPos(0);
    }
    if(posInBounds(newPos)){
        return mapa[newPos.x][newPos.y]=='0';
    }
    return false;
}
bool leftIsClear(){
    Pii frontPos;
    if(actualOrientation==0){
        frontPos=getPos(3);
    }
    if(actualOrientation==1){
        frontPos=getPos(0);
    }
    if(actualOrientation==2){
        frontPos=getPos(1);
    }
    if(actualOrientation==3){
        frontPos=getPos(2);
    }
    if(posInBounds(frontPos)){
        return mapa[frontPos.x][frontPos.y]=='0';
    }
    return false;
}
void checkSides(){
    if(rightIsClear()){
        turnRight();
    }
    else if(leftIsClear()){
        turnLeft();
    }
}
void checkFront(){
    if(!frontIsClear()){
        if(rightIsClear()){
            turnRight();
        }
        else if(leftIsClear()){
            turnLeft();
        }
        else{
            turnRight();
            turnRight();
        }
    }
    else{
        if(rightIsClear()){
            turnRight();
        }
    }
}
void movePos(){
    mark[pos.x][pos.y]++;
    if(actualOrientation==0){
        ///x-1
        pos.x--;
    }
    else if(actualOrientation==1){
        ///y+1
        pos.y++;
    }
    else if(actualOrientation==2){
        ///x+1
        pos.x++;

    }
    else if(actualOrientation==3){
        ///y-1
        pos.y--;
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while((cin >> n >> m) && n!=0 && m!=0){
        mapa.clear();
        mapa.resize(n);
        mark.clear();
        for(string &y : mapa){
            cin >> y;
            mark.push_back(vector<int>(m, 0));
        }
        actualOrientation=1;
        pos={n-1, 0};
        movePos();
        checkFront();
        while((pos.x!=n-1 || pos.y!=0) && frontIsClear()){
            movePos();
            checkFront();
        }
        vector<int> ans(5, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mapa[i][j]=='0'){
                    if(mark[i][j]>=0 && mark[i][j]<5){
                        ans[mark[i][j]]++;
                    }
                }
            }
        }
        printf("%3d%3d%3d%3d%3d\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
    }
	return 0;
}
