#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i, j;
    cin >> n;
    string s1, s2, tmp;
    while(n--){
        cin >> s1 >> s2;
        tmp=s1;
        sort(tmp.begin(), tmp.end());
        for(i=0; i<s1.length(); i++){
            if(s1[i]!=tmp[i]){
                for(j=s1.length()-1; j>i; j--){
                    if(s1[j]==tmp[i]){
                        char tmp = s1[i];
                        s1[i]=s1[j];
                        s1[j]=tmp;
                        i=s1.length();
                    }
                }
            }
        }
        if(s1<s2){
            cout << s1 << "\n";
        }
        else{
            cout << "---\n";
        }
    }
}
