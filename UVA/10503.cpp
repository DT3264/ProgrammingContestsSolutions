
// Problem : 10503 - The dominoes solitaire
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1444
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
struct Piece{
	int l;
	int r;
	bool used;
};
int n, m;
bool found;
vector<Piece> pieces;
void flip(int i){
	swap(pieces[i].l, pieces[i].r);
}
bool connect(int left, int right){
	return pieces[left].r==pieces[right].l;
}
void tryPiece(int size, int lastPos){
	if(found) return;
	if(size==n){
		if(connect(lastPos, 1)){
			found=true;
			return;
		}
	}
	for(int i=2; i<m+2; i++){
		if(!pieces[i].used){
			if(!connect(lastPos, i)){
				flip(i);
			}
			if(connect(lastPos, i)){
				pieces[i].used=true;
				tryPiece(size+1, i);
				pieces[i].used=false;
			}
		}
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    while(cin >> n >> m){
    	pieces.resize(m+2);
    	for(auto &p : pieces){
    		cin >> p.l >> p.r;
    	}
    	found=false;
    	tryPiece(0, 0);
    	cout << (found ? "YES":"NO") << "\n";
    }
    return 0;
}
