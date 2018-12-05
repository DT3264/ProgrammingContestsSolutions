#include <iostream>

using namespace std;

int arr[4];
int r, i, j;

void buscaAtras(int posAct){
    if(posAct==0)
        return;
    else{
        for(j=0; j<posAct; j++){
            if(arr[j]==arr[posAct]){
                r++;
                return;
            }
        }
    }

}

int main()
{
    for(i=0; i<4; i++){
        cin >> arr[i];
        buscaAtras(i);
    }
    cout << r;
    return 0;
}
