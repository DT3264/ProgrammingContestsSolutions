#include <iostream>

using namespace std;

char chars[4];
int charsCount[4];

int main()
{
    int charsInd = 0;
    string s;
    int i;
    cin >> s;
    for(i=0; i<s.length(); i+=4){
        if(i<s.length())
            if(s[i]!='!')
                chars[0] = s[i];
        if(i+1<s.length())
            if(s[i+1]!='!')
                chars[1] = s[i+1];
        if(i+2<s.length())
            if(s[i+2]!='!')
                chars[2] = s[i+2];
        if(i+3<s.length())
            if(s[i+3]!='!')
                chars[3] = s[i+3];
    }
    for(i=0; i<s.length(); i++){
        if(s[i]!=chars[charsInd]){
            charsCount[charsInd]++;
        }
        charsInd++;
        if(charsInd==4){
            charsInd=0;
        }
    }
    short indOfR;
    short indOfG;
    short indOfB;
    short indOfY;
    for(i=0; i<4; i++){
        if(chars[i]=='R')
            indOfR=i;
        else if(chars[i]=='G')
            indOfG=i;
        else if(chars[i]=='B')
            indOfB=i;
        else if(chars[i]=='Y')
            indOfY=i;
    }

    cout << charsCount[indOfR] << ' ' << charsCount[indOfB] << ' ' << charsCount[indOfY] << ' ' << charsCount[indOfG];
	return 0;
}
