#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
        int n, m, o;
        char op;
        cin >> n >> m;
        vector<bool> equalSize(n+1, 0);
        for(int i=0; i<m; i++){
            cin >> o;
            vector<int> balance(o*2);
            for(int &x : balance) cin >> x;
            cin >> op;
            if(op=='='){
                for(int &x : balance) equalSize[x]=1;
            }
        }
        int unEqual=-1;
        int cont=0;
        for(int i=1; i<=n; i++){
            if(!equalSize[i]){
                unEqual=i;
                cont++;
            }
        }
        if(cont==1) cout << unEqual << "\n";
        else cout << "0\n";
        if(cases>0) cout << "\n";
    }
    return 0;

}
