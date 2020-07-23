#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    map<string, int> veredicts;
    int cases;
    cin >> cases;
    string str;
    while(cases--){
    	cin >> str;
    	veredicts[str]++;
    }
    cout << "AC x " << veredicts["AC"] << "\n";
    cout << "WA x " << veredicts["WA"] << "\n";
    cout << "TLE x " << veredicts["TLE"] << "\n";
    cout << "RE x " << veredicts["RE"] << "\n";
    return 0;
}
