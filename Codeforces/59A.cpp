#include <iostream>

using namespace std;

int main()
{
    //A->65
    //Z->92
    //a->97
    //z->124
    int lowC=0, upC=0, i;
    int sLen;
    string s;
    cin >> s;
    sLen = s.length();
    for(i=0; i<sLen; i++){
        if(s[i]<97)
            upC++;
        else lowC++;
    }
    if(lowC>=upC){
        for(i=0; i<sLen; i++){
            if(s[i]<97)
                s[i]+=32;
        }
    }
    else{
        for(i=0; i<sLen; i++){
            if(s[i]>=97)
                s[i]-=32;
        }
    }
    cout << s;
	return 0;
}
