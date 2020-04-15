#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<bool>> vec;
bool isValid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}
void expandKnight(int i, int j){
    vec[i][j]=1;
    int dX[8]={-2, -2, +2, +2, -1, +1, -1, +1};
    int dY[8]={-1, +1, -1, +1, -2, -2, +2, +2};
    for(int ii=0; ii<8; ii++){
        if(isValid(i+dX[ii], j+dY[ii])){
            vec[i+dX[ii]][j+dY[ii]]=1;
        }
    }
}
void expandBishop(int i, int j, int val){
    vec[i][j]=val;
    int ii, jj;
    ii=i, jj=j;
    while(isValid(ii, jj)){
        vec[ii++][jj++]=val;
    }
    ii=i, jj=j;
    while(isValid(ii, jj)){
        vec[ii--][jj--]=val;
    }
    ii=i, jj=j;
    while(isValid(ii, jj)){
        vec[ii++][jj--]=val;
    }
    ii=i, jj=j;
    while(isValid(ii, jj)){
        vec[ii--][jj++]=val;
    }
}
void expandRock(int i, int j, int val){
    vec[i][j]=val;
    int ii, jj;
    ii=i+1;
    while(ii<n){
        vec[ii++][j]=val;
    }
    ii=i-1;
    while(ii>=0){
        vec[ii--][j]=val;
    }
    jj=j+1;
    while(jj<m){
        vec[i][jj++]=val;
    }
    jj=j-1;
    while(jj>=0){
        vec[i][jj--]=val;
    }
}
void expandKing(int i, int j){
    for(int ii=-1; ii<=1; ii++){
        for(int jj=-1; jj<=1; jj++){
            if(isValid(i+ii, j+jj)) vec[i+ii][j+jj]=1;
        }
    }
}
int actualQueens=0;
int maxQueens=0;
bool expandQueens(int col){
    if (col>=min(n, m)) return true;
    for (int i=0; i<n; i++) {
        if (isValid(i, col) && !vec[i][col]) {
            expandBishop(i, col, 1);
            expandRock(i, col, 1);
            actualQueens++;
            maxQueens=max(maxQueens, actualQueens);
            if (expandQueens(col + 1)) return true;
            actualQueens--;
            expandBishop(i, col, 0);
            expandRock(i, col, 0);
        }
    }
    return false;
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    char piece;
    int cases;
    cin >> cases;
    while(cases--){
        cin >> piece >> n >> m;
        vec.assign(n, vector<bool>(m, 0));
        int cont=0;
        if(piece=='Q'){
            actualQueens=0;
            maxQueens=0;
            expandQueens(0);
            cont=maxQueens;
        }
        else {
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vec[i][j]){
                        if(piece=='k'){
                            int ii=i, jj=j;
                            while(ii<n && jj<m){
                                expandKnight(ii++, jj++);
                                cont++;
                            }
                            continue;
                        }
                        else if(piece=='r'){
                            expandRock(i, j, 1);
                        }

                        if(piece=='K'){
                            expandKing(i, j);
                        }
                        cont++;
                    }
                }
            }
        }
        cout << cont << "\n";
    }
	return 0;
}
