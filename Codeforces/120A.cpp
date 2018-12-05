#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    string s;
    int i;
    cin >> s >> i;
    if(s=="front"){
        cout << (i==1? 'L' : 'R');
    }
    else{
        cout << (i==1? 'R' : 'L');
    }

    return 0;
}
