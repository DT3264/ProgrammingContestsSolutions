#include <iostream>

using namespace std;

int arr[5][5];
int minMovs=10000;
bool isFound=false;

void buscaRecurs(int i, int j, int nMovs){
    //cout << nMovs << endl;
    if(i<0 || i>4 || j<0 || j>4)
        return;
    else if(arr[i][j]==-1)
        return;
    else if(arr[i][j]==1){
        if(nMovs<minMovs){
            minMovs=nMovs;
        }
    }
    else{
        arr[i][j]=-1;
        buscaRecurs(i, j-1, nMovs+1);
        buscaRecurs(i, j+1, nMovs+1);
        buscaRecurs(i-1, j, nMovs+1);
        buscaRecurs(i+1, j, nMovs+1);
        arr[i][j]=0;
    }
}

int main()
{
    int i,j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }
    buscaRecurs(2, 2, 0);
    cout << minMovs;
    return 0;
}
