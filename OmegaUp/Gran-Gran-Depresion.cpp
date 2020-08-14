// Problem : B. Gran Gran Depresión
// Contest : omegaUp - Liga omegaUp - Fase 5
// URL : https://omegaup.com/arena/ligaomegaup5/practice/#problems/Gran-Gran-Depresion
// Memory Limit : 62 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct Bottle{
	int vol;
	int cal;
};
vector<Bottle> bottles;
int stomackSize;
vector<vi> dp;
int drink(int pos, int remainVol){
	//Se acabaron las botellas
    if(pos==bottles.size()) return 0;
    //Ya pasamos por aquí
    if(dp[pos][remainVol]!=-1) return dp[pos][remainVol];
    //Valores iniciales, max->0, min->1e9
    int take=0, notTake=0;
    //Se puede tomar
    if(bottles[pos].vol<=remainVol){
    	take=bottles[pos].cal+drink(pos+1, remainVol-bottles[pos].vol);
    }
    //No se puede tomar
    notTake=dp[pos][remainVol]=drink(pos+1, remainVol);
    return dp[pos][remainVol]=max(take, notTake);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cantBottles;
    int cantFriends;
    while(cin >> cantBottles){
        bottles.resize(cantBottles);
        for(auto &x : bottles) cin >> x.cal >> x.vol;
        cin >> cantFriends;
        int ans=0;
        for(int i=0; i<cantFriends; i++){
            cin >> stomackSize;
            //Tamaño dinámico
        	dp.assign(cantBottles, vi(stomackSize+1, -1));
            ans+=drink(0, stomackSize);
        }
        cout << ans << "\n";
    }
    return 0;
}