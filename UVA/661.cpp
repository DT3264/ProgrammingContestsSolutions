#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	int n, m, c;
	int cases=1;
	while((cin >> n >> m >> c) && n!=0 && m!=0 && c!=0){
		cout << "Sequence " << cases++ << "\n";
		vector<pair<bool, int>> vec(n);
		int maxC=0, actC=0, d;
		for(auto &x: vec){
			x.f=false;
			cin >> x.s;
		}
		bool fuseBlown=false;
		for(int i=0; i<m; i++){
			cin >> d;
			d--;
			if(!vec[d].f){
				//Se prendera
				actC+=vec[d].s;
			}
			else{
				//Se apagara
				actC-=vec[d].s;
			}
			vec[d].f=!vec[d].f;
			if(actC>c){
				fuseBlown=true;
			}
			maxC=max(maxC, actC);
		}
		if(fuseBlown){
			cout << "Fuse was blown.\n";
		}
		else{
			cout << "Fuse was not blown.\n";
			cout << "Maximal power consumption was " << maxC << " amperes.\n";
		}
		cout << "\n";
	}
	return 0;
}
