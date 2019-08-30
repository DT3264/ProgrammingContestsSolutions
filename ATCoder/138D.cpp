#include<bits/stdc++.h>
using namespace std;
vector<int> vec[200001];
int sum[200001];
bool visited[200001];
struct position{
	int pos;
	int sum;
};
int main(){
	int i;
	int n, q;
	int u, v, toAdd;
	scanf("%d%d", &n, &q);
	for(i=0; i<n-1; i++){
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(i=0; i<q; i++){
		scanf("%d%d", &u, &toAdd);
		sum[u]+=toAdd;
	}
	queue<position> positions;
	positions.push({1, sum[1]});
	sum[1]=0;
	position aPos;
	while(!positions.empty()){
		aPos=positions.front();
		positions.pop();
		sum[aPos.pos]+=aPos.sum;
		aPos.sum=sum[aPos.pos];
		visited[aPos.pos]=true;
		for(i=0; i<vec[aPos.pos].size(); i++){
			if(!visited[vec[aPos.pos][i]]){
				positions.push({vec[aPos.pos][i], aPos.sum});
			}
		}
	}
	for(i=1; i<=n; i++){
		printf("%d ", sum[i]);
	}
	printf("\n");
}
S