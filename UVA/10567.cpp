
// Problem : 10567 - Helping Fill Bates
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1508
// Memory Limit : 32 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
int findNext(int pos, char c, vi &indexes){
	int l=0, r=indexes.size()-1;
	int lastPos=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(indexes[mid]>=pos){
			lastPos=indexes[mid];
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return lastPos;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    string mainStr;
    int queries;
    cin >> mainStr >> queries;
    vector<vi> ocurr(100, vi());
    string actStr;
    for(int i=0; i<mainStr.size(); i++) ocurr[mainStr[i]-'A'].push_back(i);
    while(queries--){
    	cin >> actStr;
    	int start=-1, end=-1;
    	int actPos=-1
    	for(char &c : actStr){
    		actPos=findNext(actPos+1, c, ocurr[c-'A']);
    		if(actPos==-1) break;
    		if(start==-1) start=actPos;
    	}
    	if(actPos==-1){
    		cout << "Not matched\n";
    	}
    	else{
    		cout << "Matched " << start << " " << actPos << "\n";
    	}
    }
    return 0;
}
