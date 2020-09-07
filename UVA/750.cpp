#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
vector<bool> used(8);
vector<int> queens(8);
vector<vi> posibles;
bool inDiagonal(int i, int j){
	return abs(queens[i]-queens[j])==abs(i-j);
}
void generateState(int pos){
	if(pos==8){
		posibles.push_back(queens);
		return;
	}
	for(int i=0; i<8; i++){
		if(!used[i]){
			used[i]=true;
			queens[pos]=i;
			bool canGo=true;
			for(int j=0; j<pos; j++){
				if(inDiagonal(pos, j)){
					canGo=false;
				}
			}
			if(canGo) generateState(pos+1);
			used[i]=false;
		}
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    generateState(0);
    int n, m;
    int cases;
    cin >> cases;
    while(cases--){
    	cin >> n >> m;
    	cout << "SOLN       COLUMN\n";
    	cout << " #      1 2 3 4 5 6 7 8\n\n";
    	int match=1;
    	for(auto &vec : posibles){
    		if(vec[m-1]==n-1){
    			cout << setw(2) << match++ << "      ";
    			for(int i=0; i<8; i++) 
    				cout << vec[i]+1 << " \n"[i==7];
    		}
    	}
    	if(cases>0) cout << "\n";
    }
    return 0;
}
