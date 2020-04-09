#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double h, m;
    char c;
    while(cin >> h >> c >> m && (h!=0 || m!=0)){
        double oH=h*30;
        double oM=m*6;
        oH-=oM;
        oH+=m*.5;
        oH=abs(oH);
        cout << fixed << setprecision(3) << min(oH, abs(360.0-oH)) << "\n";
    }
	return 0;
}
