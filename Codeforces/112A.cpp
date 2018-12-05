#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    int i, sLen;
    cin >> s1 >> s2;
    sLen = s1.length();
    int t1, t2;
    for(i=0; i<sLen; i++){
        if((int)s1[i]>96)
            t1=(int)s1[i]-96;
        else t1=(int)s1[i]-64;
        if((int)s2[i]>96)
            t2=(int)s2[i]-96;
        else t2=(int)s2[i]-64;
        if(t1==t2)
            continue;
        else if(t1>t2){
            cout << 1;
            return 0;
        }
        else if(t2>t1){
            cout << -1;
            return 0;
        }
    }
    cout << 0;
	return 0;
}
