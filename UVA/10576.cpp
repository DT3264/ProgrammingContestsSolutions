
// Problem : 10576 - Y2K Accounting Bug
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1517
// Memory Limit : 32 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
vi vec;
vi selected;
int ans=0;
void next(int pos){
	if(pos==12){
        int sum=0;
        int period=0;
        for(int i=0; i<4; i++){
            sum+=selected[i];
        }
        period=sum;
        for(int i=4; i<12; i++){
            if(i>4) period-=selected[i-5];
            period+=selected[i];
            sum+=selected[i];
            if(period>0) return;
        }
        ans=max(ans, sum);
		return;
	}
	for(int i=0; i<2; i++){
        selected[pos]=vec[i];
		next(pos+1);
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, m;
    while(cin >> n >> m){
    	vec={n, -m};
    	selected=vi(12, 0);
    	ans=-1e9;
    	next(0);
    	if(ans>=0) cout << ans << "\n";
    	else cout << "Deficit\n";
    }
    return 0;
}
