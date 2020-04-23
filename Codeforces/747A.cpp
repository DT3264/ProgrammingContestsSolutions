#include<bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    vector<pii> vec;
    cin >> n;
    int n1, n2;
    for(n1=(n/2)+1; n1>=1; n1--){
        for(n2=1; n1*n2<=n; n2++){
            if(n1*n2==n){
                //cout << "KK\n";
                vec.push_back({n1, n2});
            }
        }
    }
    sort(vec.begin(), vec.end(), [](const pii &p1, const pii &p2){
        if(abs(p1.f-p1.s)==abs(p2.f-p2.s)){
            return p1.f<p1.s;
         }
         else{
            return abs(p1.f-p1.s)<abs(p2.f-p2.s);
         }
    });
    cout << vec[0].f << " " << vec[0].s << "\n";
    //cout << n1 << " " << n2 << "\n";
	return 0;

}
