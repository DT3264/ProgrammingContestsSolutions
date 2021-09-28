#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
template<class T>
using v=vector<T>;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	int arr[n][n];
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			cin >> arr[i][j];
    		}
    	}
    	int permuCol[n];
    	for(int i=0; i< n; i++){
    		permuCol[i]=i;
    	}
    	int bestSum=1e9;
    	do{
    		int actSum=0;
    		for(int i=0; i<n; i++){
    			int col=permuCol[i];
    			actSum+=arr[i][col];
    		}
    		bestSum=min(bestSum, actSum);
    	}while(next_permutation(permuCol, permuCol+n));
    	cout << bestSum << '\n';
    }
    return 0;
}
