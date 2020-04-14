#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n && n!=0){
        int sheets=ceil((double)n/4.0);
        vector<vector<int>> vec(sheets*2, vector<int>(2, 0));
        int actN=1;
        int actSheet=0;
        while(actSheet<sheets*2 && actN<=n){
            //cout << actSheet <<","<<(actN%2!=0) << "->" <<actN<<"\n";
            vec[actSheet++][actN%2==0]=actN++;
        }
        actSheet=(sheets*2)-1;
        while(actSheet>=0 && actN<=n){
            vec[actSheet--][actN%2==0]=actN++;
        }
        cout << "Printing order for " << n << " pages:\n";
        for(int i=0; i<sheets*2; i++){
            if(vec[i][0]==0 && vec[i][1]==0) continue;
            cout << "Sheet " << (i/2)+1 << ", ";
            cout << (i%2==0 ? "front" : "back ") << ": ";
            if(vec[i][0]==0) cout << "Blank";
            else cout << vec[i][0];
            cout << ", ";
            if(vec[i][1]==0) cout << "Blank";
            else cout << vec[i][1];
            cout << "\n";
        }
    }
	return 0;
}
