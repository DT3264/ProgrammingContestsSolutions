#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
template<class T>
using v=vector<T>;
int grid [3001][3001];
int main(){
    // printDebug=true;
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    pii p1, p2, p3, p4, p5, p6;
    cin >> p1.f >> p1.s >> p2.f >> p2.s;
    cin >> p3.f >> p3.s >> p4.f >> p4.s;
    cin >> p5.f >> p5.s >> p6.f >> p6.s;
    int ans=0;
    for(int i=p1.f; i<p2.f; i++){
    	for(int j=p1.s; j<p2.s; j++){
    		grid[i+1000][j+1000]=1;
    		ans++;
    	}
    }
    for(int i=p3.f; i<p4.f; i++){
    	for(int j=p3.s; j<p4.s; j++){
    		grid[i+1000][j+1000]=1;
    		ans++;
    	}
    }
    for(int i=p5.f; i<p6.f; i++){
    	for(int j=p5.s; j<p6.s; j++){
    		ans-=grid[i+1000][j+1000];
    	}
    }
    cout << ans << '\n';
    return 0;
}
