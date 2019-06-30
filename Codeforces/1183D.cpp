#include <bits/stdc++.h>
using namespace std;
int MAX = (200000)+2;
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	while(q--){
		int n, i, t, types=0;
		scanf("%d", &n);
		vector<int> candies(n+1);
		for(i=0; i<n; i++){
			scanf("%d", &t);
			candies[t]++;
		}
		sort(candies.rbegin(), candies.rend());
		int totalCandies=candies[0];
		int lastCandy=candies[0];
		for(i=1; i<n && candies[i]>0; i++){
			int actualCandy=candies[i];
			if(actualCandy>=lastCandy){
				actualCandy=lastCandy-1;
			}
			if(actualCandy>=0){
				totalCandies+=actualCandy;
				lastCandy=actualCandy;
			}
 
		}
		printf("%d\n", totalCandies);
	}
	return 0;
}