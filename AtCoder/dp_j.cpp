
// Problem : J - Sushi
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_j
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
#define noDebug if(!printDebug)
#define td(a) (double)(a)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
int n;
double dp[301][301][301];
double eat(int i, int j, int k){
	if(i<0 || j<0 || k<0) return 0;
	if(i+j+k==0) return 0;
	if(dp[i][j][k]>0) return dp[i][j][k];
	int remain=i+j+k;
	//If the next is an empty plate
	double w0=n;
	//If we eat a plate with 1
	double w1=i*eat(i-1,j,k);
	//If we eat a plate with 2
	double w2=j*eat(i+1,j-1,k);
	//If we eat a plate with 3
	double w3=k*eat(i,j+1,k-1);
	double val=w0+w1+w2+w3;
	return dp[i][j][k]=val/remain;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    cin >> n;
    //Since it's random, the order doesn't matter
    //Just the amount of food
    int cont[3]={0,0,0};
    for(int i=0; i<n; i++){
    	int t;
    	cin >> t;
    	cont[t-1]++;
    }
    double ans=eat(cont[0], cont[1], cont[2]);
    cout << fixed << setprecision(9) << ans << "\n";
    return 0;
}
