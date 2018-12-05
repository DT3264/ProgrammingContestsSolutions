#include <iostream>

using namespace std;

int main()
{
    int i, j, n, cont=0;
    cin >> n;
    char t;
    bool lastCharacterWasC=false;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            t = (!lastCharacterWasC?'C':'.');
            lastCharacterWasC = !lastCharacterWasC;
            if(t=='C')
                cont++;
        }
        if(n%2==0)
            lastCharacterWasC=!lastCharacterWasC;
    }
    cout << cont << '\n';
    lastCharacterWasC = false;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout << (!lastCharacterWasC?'C':'.');
            lastCharacterWasC = !lastCharacterWasC;
        }
        if(n%2==0)
            lastCharacterWasC=!lastCharacterWasC;
        cout << '\n';
    }
    return 0;
}
