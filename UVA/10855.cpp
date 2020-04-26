#include<bits/stdc++.h>
#define vc vector<char>
using namespace std;
int n, m;
int vals[4];
void checkSquares(vector<vc> &vec1, vector<vc> &vec2, int x, int y){
    int nX;
    int nY;
    bool can;
    ///Normal
    nX=0;
    nY=0;
    can=true;
    for(int i=x; i<x+m; i++){
        for(int j=y; j<y+m; j++){
            //cout << nX << "," << nY << "\n";
            if(vec1[i][j]==vec2[nX][nY]){
                nY++;
                if(nY==m){
                    nY=0;
                    nX++;
                }
            }
            else can=false, i=1e9, j=1e9;
        }
    }
    if(can){

        vals[0]++;
    }
    ///90
    nX=0;
    nY=m-1;
    can=true;
    for(int i=x; i<x+m; i++){
        for(int j=y; j<y+m; j++){
            //cout << nX << "," << nY << "\n";
            if(vec1[i][j]==vec2[nX][nY]){
                nX++;
                if(nX==m){
                    nX=0;
                    nY--;
                }
            }
            else can=false, i=1e9, j=1e9;
        }
    }
    if(can){

        vals[3]++;
    }
    ///180
    nX=m-1;
    nY=m-1;
    can=true;
    for(int i=x; i<x+m; i++){
        for(int j=y; j<y+m; j++){
            //cout << nX << "," << nY << "\n";
            if(vec1[i][j]==vec2[nX][nY]){
                nY--;
                if(nY<0){
                    nY=m-1;
                    nX--;
                }
            }
            else can=false, i=1e9, j=1e9;
        }
    }
    if(can){

        vals[2]++;
    }
    ///270
    nX=m-1;
    nY=0;
    can=true;
    for(int i=x; i<x+m; i++){
        for(int j=y; j<y+m; j++){
            //cout << nX << "," << nY << "\n";
            if(vec1[i][j]==vec2[nX][nY]){
                nX--;
                if(nX<0){
                    nX=m-1;
                    nY++;
                }
            }
            else can=false, i=1e9, j=1e9;
        }
    }
    if(can){
        vals[1]++;
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while(cin >> n >> m){
        if(n==0 && m==0){
            break;
        }
        memset(vals, 0, sizeof(vals));
        vector<vc> vec1(n, vc(n));
        vector<vc> vec2(m, vc(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> vec1[i][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cin >> vec2[i][j];
            }
        }
        for(int i=0; i<n-m+1; i++){
            for(int j=0; j<n-m+1; j++){
                //cout << "Checando en: " << i << "," << j << "\n";
                checkSquares(vec1, vec2, i, j);
            }
        }
        for(int i=0; i<3; i++){
            cout << vals[i] << " ";
        }
        cout << vals[3];
        cout << "\n";
    }
    return 0;
}
