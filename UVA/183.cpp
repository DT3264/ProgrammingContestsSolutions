#include<bits/stdc++.h>
#define f first
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
template<class T>
using v=vector<T>;
int n, m;
v<v<int>> grid;
string ans;

// The starting point, 
// the rows it contains and the columns it contains
struct Split{
	int x0, y0;
	int rows, cols;
};

v<Split> splitS(Split s){
	int cols=s.cols;
	int rows=s.rows;
	int x0=s.x0;
	int y0=s.y0;
	
	int mRows=rows/2;
	int rUp=mRows;
	int rDown=mRows;
	if(rUp+rDown<rows) rUp++;
	int mCols=cols/2;
	int cLeft=mCols;
	int cRight=mCols;
	if(cLeft+cRight<cols) cLeft++;
	// Up and down
	if(s.cols==1 && s.rows!=1){
		return {
			{x0, y0, rUp, 1},
			{x0+rUp, y0, rDown, 1}
		};
	}
	// Left and right
	else if(s.rows==1 && s.cols!=1){
		return {
			{x0, y0, 1, cLeft},
			{x0, y0+cLeft, 1, cRight}
		};
	}
	// otherwise split in 4 sections
	else{
		return {
			// Ariba izq
			{x0, y0, rUp, cLeft},
			// Arriba der
			{x0, y0+cLeft, rUp, cRight},
			// Abajo izq
			{x0+rUp, y0, rDown, cLeft},
			// Abajo der
			{x0+rUp, y0+cLeft, rDown, cRight}
		};
	}
}

void countNums(Split s, int &v0, int &v1){
	for(int i=s.x0; i<s.x0+s.rows; i++){
		for(int j=s.y0; j<s.y0+s.cols; j++){
			if(grid[i][j]==1) v1++;
			else v0++;
		}
	}
}

void encode(Split split){
	int v0=0, v1=0;
	countNums(split, v0, v1);
	if(v0!=0 && v1!=0){
		// split and encode
		ans+='D';
		auto splits=splitS(split);
		for(auto s : splits){
			encode(s);
		} 
	}
	else if(v0>0) ans+='0';
	else if(v1>0) ans+='1';
}

void decode(Split split){
	char aC;
	cin >> aC;
	if(aC=='D'){
		// split and decode
		auto splits=splitS(split);
		for(auto s : splits){
			decode(s);
		} 
	}
	else{
		for(int i=split.x0; i<split.x0+split.rows; i++){
			for(int j=split.y0; j<split.y0+split.cols; j++){
				grid[i][j]=aC-'0';
			}
		}
	}
}

int main(){
    // printDebug=true;
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    char method;
    while(cin >> method){
    	ans="";
    	if(method=='#') break;
    	cin >> n >> m;
    	grid=v<v<int>>(n, v<int>(m));
    	if(method=='B'){
    		cout << 'D';
    		cout << std::setfill (' ') << std::setw(4) << n;
    		cout << std::setfill (' ') << std::setw(4) << m;
    		cout << '\n';
    		char c;
	    	for(int i=0; i<n; i++){
	    		for(int j=0; j<m; j++){
	    			cin >> c;
	    			grid[i][j]=c-'0';
	    		}
	    	}
    		
    		encode({0, 0, n, m});
    	}
    	else{
    		cout << 'B';
    		cout << std::setfill (' ') << std::setw(4) << n;
    		cout << std::setfill (' ') << std::setw(4) << m;
    		cout << '\n';
    		decode({0, 0, n, m});
    		for(int i=0; i<n; i++){
	    		for(int j=0; j<m; j++){
	    			ans+=grid[i][j]+'0';
	    		}
	    	}
    	}
    	// cout << ans.size() << '\n';
    	for(int i=0; i<ans.size(); i++){
    		cout << ans[i];
    		if((i+1)%50==0 && i>0) cout << '\n';
    	}
    	if(ans.size()%50!=0) cout << '\n';
    }
    return 0;
}
