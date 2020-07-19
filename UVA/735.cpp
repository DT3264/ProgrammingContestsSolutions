#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    bool used[61][61][61];
    set<int> nums;
    nums.insert(0);
    nums.insert(50);
    for(int i=1; i<=20; i++){
    	nums.insert(i);
    	nums.insert(i*2);
    	nums.insert(i*3);
    }
    int n;
	while(cin >> n){
		if(n<=0) break;
		memset(used, 0, sizeof(used));
		int comb=0;
		int permu=0;
		for(int v1 : nums){
			for(int v2 : nums){
				for(int v3 : nums){
					if(v1+v2+v3==n){
						permu++;
						if(!used[v1][v2][v3]){
							used[v1][v2][v3]=1;
							used[v1][v3][v2]=1;
							used[v2][v1][v3]=1;
							used[v2][v3][v1]=1;
							used[v3][v1][v2]=1;
							used[v3][v2][v1]=1;
							comb++;
						}
					}
				}
			}
		}
		if(comb+permu>0){
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb << ".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permu << ".\n";
		}
		else{
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
		}
		cout << "**********************************************************************\n";
	}
	cout << "END OF OUTPUT\n";
    return 0;
}
