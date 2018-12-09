#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int ta, i;
    int contPar=0, contNon=0;
    int indPar=0, indNon=0;
    for(i=0; i<a; i++){
        cin >> ta;
        if(ta%2==0){
            contPar++;
            indPar=i;
        }
        else{
            contNon++;
            indNon=i;
        }
    }
    cout << (contPar>1 ? indNon : indPar)+1;
    return 0;
}
