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
    while(cin >> n && n!=0){
        cin.ignore();
        vector<int> vec(n, 0);
        int minSpaces=-1;
        for(int &x : vec){
            getline(cin, str);
            for(char &c : str){
                if(c==' ') x++;
            }
            if(minSpaces==-1) minSpaces=x;
            else minSpaces=min(minSpaces, x);
        }
        int ans=0;
        for(int &x : vec){
            ans+=x-minSpaces;
        }
        cout << ans << "\n";
    }
    return 0;

}
