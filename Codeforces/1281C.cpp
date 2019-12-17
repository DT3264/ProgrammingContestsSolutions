#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long i, j;
    long long n;
    long long x;
    string s;
    cin >> n;
    while(n--){
        s="";
        cin >> x >> s;
        int pos=0;
        long long actLen=s.length();
        while(s.length() < x){
            string tempS = s.substr(pos+1, string::npos);
            for(i='0'; i<s[pos]-1; i++){
                for(j=0; j<tempS.length() && s.length() < x; j++){
                    s+=tempS[j];
                }
            }
            pos++;
        }
        long long ans;
        for(i=0; i<x; i++){
            long long mult = s[i]-'0';
            actLen = (i+1)+(((actLen-(i+1))%mod)*(mult%mod));
            //cout << actLen<< "\n";
        }

        cout << actLen%mod << "\n";
    }
}
