#include <iostream>

using namespace std;

bool bArr[100];
int arr[100];
int boxes, i, t;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> boxes;
    for(i=0; i<boxes; i++){
        cin >> t;
        arr[t-1]++;
    }
    for(i=0; i<100; i++){
        while(arr[i]>0){
            cout << i+1;
            arr[i]--;
            boxes--;
            if(boxes>0)
                cout << " ";
            else i=100;
        }
    }
    return 0;
}
