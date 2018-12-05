#include <bits/stdc++.h>

using namespace std;

int main() {
    int z;
    cin >> z;
    for(z=z; z>0; z--)
    {
        string a=" ";
        cin >> a;
        int b;
        b=a.length();
        if(b>10)
        {
            cout << a[0] << b-2 << a[b-1] << endl;
        }
        else
        {
            cout << a << endl;
        }
    }
    return 0;
}
