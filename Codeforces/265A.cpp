#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    int actualPos=0, i, sLen;
    cin >> s1 >> s2;
    sLen = s2.length();
    for(i=0; i<sLen; i++){
        if(s2[i]==s1[actualPos]){
            actualPos++;
        }
    }
    cout << actualPos+1;
    return 0;
}
