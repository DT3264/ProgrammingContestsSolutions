#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, i, x=0;
    string z;
    cin >> a;
    for(i=0; i<a; i++)
    {
        cin >> z;
        if((z[0]=='+'&&z[1]=='+') || (z[1]=='+'&&z[2]=='+') || (z[0]=='+'&&z[2]=='+'))
            x++;
        if((z[0]=='-'&&z[1]=='-') || (z[1]=='-'&&z[2]=='-') || (z[0]=='-'&&z[2]=='-'))
            x--;
    }
    cout << x;
    return 0;
}
