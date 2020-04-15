#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<bool>> vec;
bool isValid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}
void expandKnight(int i, int j){
    //cout << "POS: " << i << "," << j << "\n";
    vec[i][j]=1;
    int dX[8]={-2, -2, +2, +2, -1, +1, -1, +1};
    int dY[8]={-1, +1, -1, +1, -2, -2, +2, +2};
    for(int ii=0; ii<8; ii++){
        if(isValid(i+dX[ii], j+dY[ii])){
            //cout << i+dX[ii] << "," << j+dY[ii] << "\n";
            vec[i+dX[ii]][j+dY[ii]]=1;
        }
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char piece;
    while((cin >> n >> m) && (n!=0 || m!=0)){
        vec.assign(n, vector<bool>(m, 0));
        int cont=0;
        if(min(n, m)==0){
            cont=0;
        }
        else if(min(n, m)==1){
            cont=max(n, m);
        }
        else if(min(n, m)==2){
            bool shouldCount=true;
            int relativePos=0;
            int actualKnights=0;
            for(int i=0; i<max(n, m); i++){
                if(shouldCount && relativePos<2){
                    actualKnights+=2;
                }
                relativePos++;
                if(relativePos==2){
                    relativePos=0;
                    shouldCount=!shouldCount;
                }
            }
            cont=actualKnights;
        }
        else{
            cont=((n*m)+1)/2;
        }
        cout << cont;
        cout << " knights may be placed on a " << n;
        cout << " row " << m << " column board." << "\n";
    }
	return 0;
}
