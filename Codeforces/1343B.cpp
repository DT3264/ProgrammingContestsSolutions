#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n, m;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        cout << (m%4==0 ? "YES" : "NO") << "\n";
        if(m%4==0){
            int i=1;
            vector<int> odd;
            vector<int> even;
            while(i<m){
                odd.push_back(i++);
                even.push_back(i++);
            }
            int sumOdd=0, sumEven=0;
            for(int &x : odd){
                sumOdd+=x;
            }
            for(int &x : even){
                sumEven+=x;
            }
            odd[odd.size()-1]+=sumEven-sumOdd;

            for(int &x : even){
                cout << x << " ";
            }
            cout << odd[0];
            for(int i=1; i<odd.size(); i++){
                cout << " " << odd[i];
            }
            cout << "\n";
        }
    }
	return 0;

}
