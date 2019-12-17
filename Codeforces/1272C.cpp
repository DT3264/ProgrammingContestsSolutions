#include<bits/stdc++.h>
using namespace std;
bool canUse[27];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, i;
    int t;
    char b;
    string str;
    cin >> n >> k;
    cin >> str;
    for(i=0; i<k; i++){
        cin >> b;
        canUse[b-'a']=1;
    }
    long long ans=0;
    for(i=0; i<str.length(); i++){
        if(canUse[str[i]-'a']){
            long long consec=0;
            long long nIndex=i+1;
            ans++;
            while(nIndex<str.length() && canUse[str[nIndex]-'a']){
                consec++;
                ans+=consec+1;
                nIndex++;
            }
            i=nIndex-1;
        }
    }
    cout << ans << endl;
}
