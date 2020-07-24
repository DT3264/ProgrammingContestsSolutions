
// Problem : 11085 - Back to the 8-Queens
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2026
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
vi recurrState;
vector<vi> states;
bool used[8];
bool inDiagonal(int i, int j, int k, int l){
	return abs(i-k)==abs(j-l);
}
void avoid(int pos){
	if(pos==8){
		states.push_back(recurrState);
		return;
	}
	for(int i=1; i<=8; i++){
		bool further=true;
		if(!used[i]){
			used[i]=true;
			recurrState[pos]=i;
			for(int j=0; j<pos; j++){
				if(inDiagonal(j, recurrState[j]-1, pos, recurrState[pos]-1)){
                    further=false;
                    break;
				}
			}
			if(further){
				avoid(pos+1);
			}
			used[i]=false;
		}
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int actCase=1;
    recurrState=vi(8, 1);
    avoid(0);
    string str;
    while(getline(cin, str)){
    	stringstream ss(str);
    	vi actState(8);
        for(int &x : actState) ss >> x;
        int minChanges=9;
        for(vi &goodState : states){
        	int actChanges=0;
        	for(int i=0; i<8; i++){
        		actChanges+=actState[i]!=goodState[i];
        	}
        	minChanges=min(minChanges, actChanges);
        }
        cout << "Case " << actCase++ << ": " << minChanges << "\n";
    }
    return 0;
}
