#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool arr[3][3];
int main(){
	memset(arr, 1, sizeof(arr));
	int i, j, k, t;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &t);
			t%=2;
			if(t==1){
				arr[i][j]=!arr[i][j];
				for(k=0; k<4; k++){
					if(i+dx[k]>=0 && i+dx[k]<3 && j+dy[k]>=0 && j+dy[k]<3){
						arr[i+dx[k]][j+dy[k]]=!arr[i+dx[k]][j+dy[k]];
					}
				}
			}
		}
	}
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}