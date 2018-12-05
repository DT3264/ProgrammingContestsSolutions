#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int kids;
    int progC[5000], indProg=0;
    int mathC[5000], indMath=0;
    int peC[5000], indPE=0;
    cin >> kids;
    int t, i;
    for(i=1; i<=kids; i++){
        cin >> t;
        if(t==1){
            progC[indProg]=i;
            indProg++;
        }
        else if(t==2){
            mathC[indMath]=i;
            indMath++;
        }
        else if(t==3){
            peC[indPE]=i;
            indPE++;
        }
    }
    if(!(indProg>0 && indMath>0 && indPE>0))
        cout << 0;
    int minI;
    if(indProg>0 && indMath>0 && indPE>0){
        minI=5001;
        if (indProg<minI) minI = indProg;
        if (indMath<minI) minI = indMath;
        if (indPE<minI) minI = indPE;
        cout << minI << '\n';
        for(i=0; i<minI; i++){
            cout << progC[i] << ' ' << mathC[i] << ' ' << peC[i] << '\n';
        }

    }
    return 0;
}
