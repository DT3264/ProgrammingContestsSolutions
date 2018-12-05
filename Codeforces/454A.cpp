#include <iostream>

using namespace std;

int main()
{
    int a, b=1, c, d=1, i, j, k, l, m;
    cin >> a;
    c=a;
    a=(a+1)/2;
    for(i=1; i<=a; i++)
    {
        for(j=i; j<a; j++)
        {
            cout << "*";
        }
        for(k=1; k<=b; k++)
        {
            cout << "D";
        }
        b+=2;
        for(j=i; j<a; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    c-=2;
    while(c>=0)
    {
        for(m=1; m<=d; m++)
        {
            cout << "*";
        }
        for(l=1; l<=c; l++)
        {
            cout << "D";
        }
        for(m=1; m<=d; m++)
        {
            cout << "*";
        }
        d++;
        cout << endl;
        c-=2;
    }
    return 0;
}
