#include <bits/stdc++.h>
using namespace std;
struct h{
	int num;
	vector<int> vec;
};
vector<int> vec[100001];
vector<h> helpVec;

int main(){
	int n, m, i, j, t;
	scanf("%d%d", &n, &m);
	
	for(i=1; i<=n; i++){
		vec[i].push_back(-1);
	}
	for(i=0; i<n; i++){
		scanf("%d", &t);
		if(t<=n){
			//printf("pushing %d\n", t);
			vec[t].push_back(i+1);
		}
	}
	for(i=1; i<=n; i++){
		vec[i].push_back(2000000);
	}
	
	for(i=1; i<=n; i++){
		//printf("size of: %d: %d\n", i, vec[i].size());
		if(vec[i].size()>=i+2){
			//printf("Vec: %d has %d\n", i, vec[i].size());
			helpVec.push_back({i, vec[i]});
		}
	}
	
	int l, r;
	for(i=0; i<m; i++){
		scanf("%d%d", &l, &r);
		int ans=0;
		for(j=0; j<helpVec.size(); j++){
			auto lIter=lower_bound(helpVec[j].vec.begin(), helpVec[j].vec.end(), l);
			auto rIter=upper_bound(helpVec[j].vec.begin(), helpVec[j].vec.end(), r);
			int lInd=lIter-helpVec[j].vec.begin();
			int rInd=rIter-helpVec[j].vec.begin();
			rInd-1;
			if(rInd-lInd==helpVec[j].num){
				ans++;
			}
			//printf("%d to %d with %d\n", lInd, rInd, helpVec[j].num);
		}
		printf("%d\n", ans);
	}
}