#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct Car{
    string maker;
    int low, high;
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    int actCase=1;
    while(cases--){
        if(actCase++>1) cout << "\n";
        int nCars;
        cin >> nCars;
        debug cout << nCars << " cars\n";
        vector<Car> cars(nCars);
        for(Car &c : cars){
            cin >> c.maker >> c.low >> c.high;
        }
        int queries, price;
        cin >> queries;
        while(queries--){
            cin >> price;
            int ans=0;
            string ansMaker="";
            debug cout << "Price: " << price << "\n";
            for(Car &c : cars){
                debug  cout << c.low << " " << c.high << "\n";
                if(c.low<=price && c.high>=price){
                    ans++;
                    ansMaker=c.maker;
                }
                if(ans==2) break;
            }
            debug cout << "Matches: " << ans << "\n";
            cout << (ans==1 ? ansMaker : "UNDETERMINED") << "\n";
        }
    }
    return 0;

}
