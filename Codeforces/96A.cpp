#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a0=0, a1=0, i, lado, x=0;
    string z;
    cin >> z;
    if(z[0]=='0')
        lado=0;
    else
        lado=1;
    for(i=0; i<z.length(); i++)
    {
        if(z[i]=='0' && lado==0)
            x++;
        else if(z[i]=='0' && lado==1)
        {
            x=1;
            lado=0;
        }
        if(z[i]=='1' && lado==1)
            x++;
        else if(z[i]=='1' && lado==0)
        {
            x=1;
            lado=1;
        }
        if(x>6)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
