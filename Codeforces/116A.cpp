#include <iostream>
#include <stdio.h>

using namespace std;

long long a, amax, b, c, i, z;

int main()
{
    cin >> a;
    for(i=0; i<a; i++)
    {
        cin >> b >> c;
        z-=b;
        z+=c;
        if(z>amax)
            amax=z;
    }
    cout << amax;
    return 0;
}
