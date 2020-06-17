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
    int t;
    string str;
    int actCase=1;
    cin >> t;
    while(t--){
        vector<int> vec(100, 0);
        int pos=0;
        cin >> str;
        for(char &c : str){
            if(c=='>') pos++;
            else if(c=='<') pos--;
            else if(c=='+') vec[pos]++;
            else if(c=='-') vec[pos]--;
            if(pos>99) pos=0;
            if(pos<0) pos=99;
            if(vec[pos]>255) vec[pos]=0;
            if(vec[pos]<0) vec[pos]=255;
        }
        cout << "Case " << actCase++ << ":";
        for(int &x : vec){
            stringstream ss;
            ss << hex << setfill('0') << setw(2) << x;
            ss >> str;
            for(char &c : str) c=toupper(c);
            cout << " " << str;
        }
        cout << "\n";
    }
    return 0;

}
