#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string a;
    int i, z;
    cin >> a;
    z=a.length();
    for(i=0; i<z; i++)
    {
        if(a[i]>64 && a[i]<91)
        {
            a[i]+=32;
        }
    }
    for(i=0; i<z; i++)
    {
        if(a[i]=='a' || a[i]=='o' || a[i]=='y' || a[i]=='e' || a[i]=='u' || a[i]=='i')
        {
            continue;
        }
        else
        {
            cout << "." << a[i];
        }
    }
    return 0;
}
