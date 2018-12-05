#include <iostream>

using namespace std;

int main()
{
    int games;
    int a=0, d=0, i;
    char t;
    cin >> games;
    for(i=0; i<games; i++){
        cin >> t;
        if(t=='A')
            a++;
        else d++;
    }
    if(a==d) cout << "Friendship";
    else if(a>d) cout << "Anton";
    else cout << "Danik";
    return 0;
}
