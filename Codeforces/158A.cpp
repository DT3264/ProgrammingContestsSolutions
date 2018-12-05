#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[100], n, k, i, z=0;
    cin >> n >> k;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    k=arr[k-1];
    for(i=0; i<n; i++)
    {
        if(arr[i]>=k && arr[i]!=0)
            z++;
    }
    cout << z;
    return 0;
}
