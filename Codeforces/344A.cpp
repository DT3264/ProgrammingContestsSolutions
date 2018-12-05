#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int nMagnets, magnet, groups=1, i;
    bool magnets[100000];
    cin >> nMagnets;
    for(i=0; i<nMagnets; i++){
        cin >> magnet;
        if(magnet==10) magnets[i]=true;
        else magnets[i]=false;
    }
    for(i=1; i<nMagnets; i++){
        if(!(magnets[i]==magnets[i-1]))
        groups++;
    }
    cout << groups;
    return 0;
}
