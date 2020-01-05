#include<bits/stdc++.h>
using namespace std;
struct P{
	long long n;//The actual number
	long long s;//The start number/tree
};
map<long long, bool> visited;
queue<P> pos;
vector<long long> ansVec;
long long uLimit = 2e9;
long long lLimit = -uLimit;

int main(){
	long long n, m, t, i;
	long long ansDist=0;
	long long arr[200000];
	scanf("%lld%lld", &n, &m);
	for(i=0; i<n; i++){
		scanf("%lld", &arr[i]);
		visited[arr[i]]=true;
		pos.push({arr[i], arr[i]});
	}
	while(ansVec.size()!=m){
		P act = pos.front(); pos.pop();
		if(act.n<lLimit || act.n>uLimit) continue;
		if(!visited[act.n]){
			ansVec.push_back(act.n);
			ansDist+=abs(act.n-act.s);
		}
		if(!visited[act.n-1]) pos.push({act.n-1, act.s});
		if(!visited[act.n+1]) pos.push({act.n+1, act.s});
		visited[act.n]=true;
	}
	printf("%lld\n", ansDist);
	for(i=0; i<ansVec.size(); i++){
		printf("%lld ", ansVec[i]);
	}
	return 0;
}