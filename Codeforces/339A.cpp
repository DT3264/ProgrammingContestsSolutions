#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    string z;
    int arr[101], i, x=0;
    cin >> z;
    for(i=0; i<z.length(); i++)
    {
        if(z[i]!='+')
        {
            arr[x]=z[i]-48;
            x++;
        }
    }
    sort(arr, arr+x);
    cout << arr[0];
    for(i=1; i<x; i++)
        cout << "+" << arr[i];
    return 0;
}
