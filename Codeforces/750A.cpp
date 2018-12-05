#include <iostream>
#include <stdio.h>

using namespace std;

long long a, t, i, p, z;

int main()
{
    cin >> a >> t;
    for(i=1; i<=a; i++)
    {
        z+=5*i;
        p++;
        if(z+t>240)
        {
            p--;
            break;
        }
    }
    cout << p;
    return 0;
}
