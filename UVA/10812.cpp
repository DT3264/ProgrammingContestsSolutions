#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases, n, m;
    cin >> cases;
    int n1, n2;
    int diffToAns;
    while(cases--){
        cin >> n >> m;
        n1=n;
        n2=n-m;
        diffToAns=(n1+n2)-n;
        n1-=diffToAns/2;
        n2-=diffToAns/2;
        //cout << n1+n2 << "\n";
        if(n1+n2==n && abs(n1-n2)==m && n1>=0 && n2>=0){
            cout << n1 << " " << n2 << "\n";
        }
        else{
            cout << "impossible\n";
        }
    }
	return 0;
}
