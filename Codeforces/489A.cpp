#include<iostream>
using namespace std;

int arr[3001];
int arrSwaps[3001][2];

int main(){
    int n, i, j;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> arr[i];
    }

    int pivMin, seguidos=0, swaps=0;
    int tempGreater;
    for(i=0; i<n; i++){
        pivMin = i;
        seguidos = 0;
        for(j=i+1; j<n; j++){
                //cout << arr[pivMin] << " - " << arr[j] <<endl;
            if(arr[pivMin]>arr[j]){
                pivMin = j;
            }
            ///else seguidos++;
        }
        tempGreater = arr[i];
        arr[i] = arr[pivMin];
        arr[pivMin] = tempGreater;
        arrSwaps[swaps][0] = i;
        arrSwaps[swaps++][1] = pivMin;
        /*for(j=0; j<n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;*/
    }
    cout << swaps << '\n';
    for(i=0; i<swaps; i++){
        cout << arrSwaps[i][0] << " " << arrSwaps[i][1] << '\n';
    }
    return 0;
}
