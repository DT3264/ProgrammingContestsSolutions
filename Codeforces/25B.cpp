#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, i;
    string s;
    cin >> a;
    cin >> s;
    i=0;
    while(a>4){
        cout << s[i] << s[i+1] << s[i+2] << "-";
        i+=3;
        a-=3;

    }
    if(a==4)
        cout << s[i] << s[i+1] << "-" << s[i+2] << s[i+3];
    else if(a==3)
        cout << s[i] << s[i+1] << s[i+2];
    else if(a==2)
        cout << s[i] << s[i+1];

    return 0;
}
