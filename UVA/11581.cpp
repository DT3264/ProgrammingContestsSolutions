#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define pii pair<ll, ll>
#define ll long long
using namespace std;
int mat[3][3];
int dX[4]={-1, 1, 0, 0};
int dY[4]={0, 0, -1, 1};
vector<string> vec;
bool isValid(int x, int y){
    return x>=0 && x<3 && y>=0 && y<3;
}
bool generateNext(){
    int newMat[3][3];
    int sum=0;
    memset(newMat, 0, sizeof(newMat));
    string str="";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<4; k++){
                int nX=i+dX[k];
                int nY=j+dY[k];
                if(isValid(nX, nY)){
                    newMat[i][j]+=mat[nX][nY];
                }
            }
            newMat[i][j]%=2;
            sum+=newMat[i][j];
            str+=newMat[i][j]+'0';
        }
    }
    memcpy(mat, newMat, sizeof(newMat));
    for(int i=0; i<vec.size(); i++){
        if(vec[i]==str) return false;
    }
    vec.push_back(str);
    return sum>0;
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        vec.clear();
        int ans=0;
        int sum=0;
        string str="";
        char actChar;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cin >> actChar;
                mat[i][j]=actChar-'0';
                sum+=mat[i][j];
                str+=mat[i][j]+'0';
            }
        }
        vec.push_back(str);
        while(generateNext()){
            ans++;
        }
        if(sum==0) ans=-1;
        cout << ans << "\n";
    }
    return 0;
}
