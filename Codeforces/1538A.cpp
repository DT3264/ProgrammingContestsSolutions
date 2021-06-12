
// Problem : A. Stone Game
// Contest : Codeforces - Codeforces Round #725 (Div. 3)
// URL : https://codeforces.com/contest/1538/problem/0
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
    	int t;
    	int minN=1e9;
    	int minPosN=-1;
    	int maxN=0;
    	int maxPosN=-1;
    	for(int i=0; i<n; i++){
    		cin >> t;
    		if(t>maxN){
    			maxN=t;
    			maxPosN=i+1;
    		}
    		if(t<minN){
    			minN=t;
    			minPosN=i+1;
    		}
    	}
    	//Si es mejor tomar el menor de la izq o der
    	int ansL=min(minPosN, n-minPosN+1);
    	//Si es mejor tomar el mayor de la izq o der
    	int ansR=min(maxPosN, n-maxPosN+1);
    	//La distancia entre ambos
    	int dist=max(maxPosN, minPosN)-min(maxPosN, minPosN);
    	//La respuesta con el menor al mayor o del mayor al menor
    	int ans=min(ansL+dist, ansR+dist);
    	//O si es mejor tomarlos por separado
    	ans=min(ans, ansL+ansR);
    	cout << ans << "\n";
    }
    return 0;
}
