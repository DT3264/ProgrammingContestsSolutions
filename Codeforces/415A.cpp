#include<iostream>
#include<string.h>
using namespace std;
int focos[100];
int main(){
    int n, m;
    int foco, i, j;
    memset(focos, 0, sizeof(focos));
    cin >> n >> m;
    for(i=0; i<m; i++){
        cin >> foco;
        for(j=foco-1; j<n; j++){
            if(focos[j]==0){
                focos[j]=foco;
            }
        }
    }
    for(i=0; i<n; i++){
        cout << focos[i] << " ";
    }
}
