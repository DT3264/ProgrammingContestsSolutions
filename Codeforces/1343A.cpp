#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    long long n, m;
    int k=0;
    vector<long long> posibles;
    vector<long long> sumTo;
    while(pow(2, k)<=10000000000){
        posibles.push_back(pow(2, k++));
    }
    sumTo.push_back(1);
    for(int i=1; i<posibles.size(); i++){
        sumTo.push_back(posibles[i]+sumTo[i-1]);
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        //cout << "For " << m << "\n";
        long long ans=-1;
        for(auto x : sumTo){
            if(x==1) continue;
            if(x>m || ans!=-1) break;
            //cout << m/x << "\n";
            if((m/x)*x==m){
                ans=m/x;
            }
        }
        cout << ans << "\n";
    }
	return 0;

}
