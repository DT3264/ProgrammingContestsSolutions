#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    if((a%2==0)&&(a!=2))
    {
        cout << "YES";
    }
    if((a%2!=0)||(a==2))
    {
        cout << "NO";
    }
    return 0;
}
