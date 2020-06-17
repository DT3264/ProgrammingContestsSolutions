#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n;
    string str;
    while(cin >> str && str!="0"){
        n=stoi(str);
        cin >> str;
        int bestAns=1e9;
        int lastChar, lastPos;
        for(int i=0; i<str.size(); i++){
            if(str[i]!='.'){
                lastChar=str[i];
                lastPos=i;
                break;
            }
        }
        if(lastChar=='Z') bestAns=0;
        for(int i=lastPos+1; i<str.size(); i++){
            if(str[i]=='Z'){
                bestAns=0;
                break;
            }
            else if(str[i]=='R'){
                if(lastChar=='R') lastPos=i;
                else{
                    bestAns=min(bestAns, i-lastPos);
                    lastChar=str[i];
                    lastPos=i;
                }
            }
            else if(str[i]=='D'){
                if(lastChar=='D') lastPos=i;
                else{
                    bestAns=min(bestAns, i-lastPos);
                    lastChar=str[i];
                    lastPos=i;
                }
            }
        }
        cout << bestAns << "\n";
    }
    return 0;

}
