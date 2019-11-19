#include <bits/stdc++.h>
using namespace std;
bool arr[101][101][101];
int main(){
    freopen("out.txt", "w", stdout);
    int a, b, c;
    int i, j, k;
    arr[1][0][0]=1;
    arr[0][1][0]=1;
    arr[0][0][1]=1;
    arr[0][2][0]=1;
    arr[0][0][2]=1;
    arr[0][0][3]=1;

    arr[0][1][1]=1;
    arr[1][0][1]=1;
    arr[1][1][0]=1;
    arr[1][1][1]=1;
    for(i=0; i<=100; i++){
        for(j=0; j<=100; j++){
            for(k=0; k<=100; k++){
                if(i-1>=0 && arr[i-1][j][k]==0){
                    arr[i][j][k]=1;
                }
                if(j-1>=0 && arr[i][j-1][k]==0){
                    arr[i][j][k]=1;
                }
                if(k-1>=0 && arr[i][j][k-1]==0){
                    arr[i][j][k]=1;
                }
                if(i+j+k>0 && arr[max(i-1, 0)][max(j-1, 0)][max(k-1, 0)]==0){
                    arr[i][j][k]=1;
                }
                if(j-2>=0 && arr[i][j-2][k]==0){
                    arr[i][j][k]=1;
                }
                if(k-2>=0 && arr[i][j][k-2]==0){
                    arr[i][j][k]=1;
                }
                if(k-3>=0 && arr[i][j][k-3]==0){
                    arr[i][j][k]=1;
                }
            }

        }
    }
    while(cin >> a >> b >> c && (a!=0 || b!=0 || c!=0)){
        printf("%d %d %d %s wins\n", a, b, c, arr[a][b][c]  ? "Bilbo" : "Frodo");
    }
    printf("\n");
}
