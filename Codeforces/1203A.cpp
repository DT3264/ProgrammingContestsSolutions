#include<stdio.h>
void adjustPos(int &x, int &n){
	if(x<0){
		x+=n;
	}
	if(x>=n){
		x-=n;
	}
}
int main(){
	int q;
	int arr[200];
	scanf("%d", &q);
	while(q--){
		int n, i, startPos;
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%d", &arr[i]);
			if(arr[i]==1){
				startPos=i;
			}
		}
		int lPos=startPos-1, rPos=startPos+1;
		int nE=2;
		adjustPos(lPos, n);
		adjustPos(rPos, n);
		bool can=true;
		while(can && arr[lPos]!=1 && arr[rPos]!=1){
			bool move=false;
			if(arr[lPos]==nE){
				lPos--;
				move=true;
			}
			if(arr[rPos]==nE){
				rPos++;
				move=true;
			}
			if(move){
				nE++;
			}
			else{
				can=false;
			}
			adjustPos(lPos, n);
			adjustPos(rPos, n);
		}
		if(can && (arr[lPos]==1 or arr[rPos]==1)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}