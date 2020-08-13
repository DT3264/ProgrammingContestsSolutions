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
struct Botella{
	int vol;
	int cal;
};
vector<Botella> botellas;
int estomago;
vector<vi> dp;
int drink(int pos, int vol){
	//Se acabaron las botellas
    if(pos==botellas.size()) return 0;
    //Ya pasamos por aquí
    if(dp[pos][vol]!=-1) return dp[pos][vol];
    //Se pasa de lo que se puede tomar
    if(botellas[pos].vol>vol){
    	dp[pos][vol]=drink(pos+1, vol);
    	return dp[pos][vol];
    }
    //Si se puede
    else{
    	//Lo tomo
	    int take=botellas[pos].cal+drink(pos+1, vol-botellas[pos].vol);
	    //No lo tomo
        int notTake=drink(pos+1, vol);
        dp[pos][vol]=max(take, notTake); 
	    return dp[pos][vol];
    }
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cantBotellas;
    int cantAmigos;
    while(cin >> cantBotellas){
        botellas.resize(cantBotellas);
        for(auto &x : botellas) cin >> x.cal >> x.vol;
        cin >> cantAmigos;
        int ans=0;
        for(int i=0; i<cantAmigos; i++){
            cin >> estomago;
            //Tamaño dinámico
        	dp.assign(cantBotellas, vi(estomago+1, -1));
            ans+=drink(0, estomago);
        }
        cout << ans << "\n";
    }
    return 0;
}