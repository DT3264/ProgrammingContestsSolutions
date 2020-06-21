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
    int setN=1;
    string str;
    while(cin >> n && n!=0){
        vector<int> vec(n);
        int sum=0;
        int ans=0;
        for(int &x : vec){
            cin >> x;
            sum+=x;
        }
        int eq=sum/n;
        for(int &x : vec){
            if(x>eq) ans+=x-eq;
        }
        cout << "Set #" << setN++ << "\n";
        cout << "The minimum number of moves is " << ans << ".\n\n";
    }
    return 0;

}
