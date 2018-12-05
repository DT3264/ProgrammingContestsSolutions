#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int arr[200000];

int main()
{
    int i;
    int a;
    scanf("%d", &a);
    for(i=0; i<a; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+a);
    intmax_t amin;
    int t, z;
    for(i=0; i<a-1; i++)
    {
        t=abs(arr[i]-arr[i+1]);
        if(t<amin)
        {
            amin=t;
            z=1;
        }
        else if(t==amin)
            z++;
    }
    cout << amin << " " << z;
return 0;
}
