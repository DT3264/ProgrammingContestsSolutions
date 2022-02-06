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
struct Case{
	int a, b, c;
};
int main(){
    // printDebug=true;
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n;
    cin >> n;
    v<Case> cases(n);
    for(auto &c : cases){
    	cin >> c.a >> c.b >> c.c;
    }
    int best=0;
    // Empieza en 1
    v<int> marbles={1,0,0};
    int act=0;
    for(auto &c : cases){
    	swap(marbles[c.a-1], marbles[c.b-1]);
    	act+=marbles[c.c-1];
    }
    best = max(best, act);
    // Empieza en 2
    marbles={0,1,0}; 
    act=0;
    for(auto &c : cases){
    	swap(marbles[c.a-1], marbles[c.b-1]);
    	act+=marbles[c.c-1];
    }
    best = max(best, act);
    // Empieza en 3
    marbles={0,0,1};
    act=0;
    for(auto &c : cases){
    	swap(marbles[c.a-1], marbles[c.b-1]);
    	act+=marbles[c.c-1];
    }
    best = max(best, act);
    cout << best << '\n';
    return 0;
}
