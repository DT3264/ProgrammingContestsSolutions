#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c, i, j, z=0;
    cin >> a;
    for(i=0; i<a; i++)
    {
        c=0;
        for(j=0; j<3; j++)
        {
            cin >> b;
            if(b==1)
                c++;
        }
        if(c>1)
            z++;
    }
    cout << z;
    return 0;
}
