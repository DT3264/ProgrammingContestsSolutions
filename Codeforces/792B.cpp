#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int jp[100];
bool arr[100];
int a, b, i, t, lid;

void gg()
{
    if(arr[lid])
        while(arr[lid] && lid<a)
            lid++;
    if(lid==a)
    {
        lid=0;
        while(arr[lid] && lid<a)
            lid++;
    }
}

int main()
{
    cin >> a >> b;
    for(i=0; i<b; i++)
    {
        cin >> jp[i];
    }
    for(i=0; i<b; i++)
    {
        t=0;
        while(t<jp[i]%(a-i))
        {
            if(!arr[lid])
            {
                lid++;
                gg();
            }
            t++;
        }
        gg();
        cout << lid+1 << " ";
        arr[lid]=1;
        lid++;
        gg();
    }
return 0;
}