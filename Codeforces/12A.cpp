#include <iostream>

using namespace std;

int main()
{
    int i, j;
    char arr[3][3];
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(arr[i][j]!=arr[2-i][2-j]){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
