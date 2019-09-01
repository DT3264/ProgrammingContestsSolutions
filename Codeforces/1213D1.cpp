#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k, i, j, p, arr[50];
	int maxN=0;
	scanf("%d%d", &n, &k);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
		maxN=max(arr[i], maxN);
	}
	sort(arr, arr+n);
	int actAns=0, ans=1000000000;
	int contEqual=0;
	/*para potencias de 2*/
	for(i=0; i<n; i++){
		for(p=0; p<18; p++){
			int x=arr[i]/(pow(2, p));
			contEqual=0;
			actAns=0;
			for(j=0; j<n; j++){
				int y=arr[j];
				int tmpAns=0;
				//printf("%d->%d ", y, j);
				while(y>x){
					y=floor(y/2.0);
					tmpAns++;
				}
				//printf(" x: %d, y: %d ", x, y);
				if(y==x){
					actAns+=tmpAns;
					contEqual++;
				}
				//printf("actAns: %d, contEqual: %d\n", actAns, contEqual);
				if(contEqual==k){
					//printf("AmonosAlv con: %d\n\n", actAns);
					ans=min(actAns, ans);
					break;
				}
			}
			if(contEqual==k){
				ans=min(actAns, ans);
			}
		}
	}
	printf("%d\n", ans);
}