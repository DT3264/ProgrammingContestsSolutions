#include <iostream>
#include <fstream>

using namespace std;
bool asks[1000];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, i;
    cin >> n >> k;
    for(i=0; i<n; i++){
        cin >> asks[i];
    }
    int piv=k;
    if(asks[piv-1]){
        cout << piv;
        return 0;
    }
    while(!asks[piv-1]){
        piv++;
        if(piv>n)
            piv=0;
    }
    cout << piv;
    return 0;
}
