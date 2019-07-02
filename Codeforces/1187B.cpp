#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, i;
	string s, s2;
	vector<vector<int>> vec(28);
	cin >> n >> s >> q;
	for(i=0; i<s.length(); i++){
        vec[s[i]-'a'].push_back(i+1);
	}
	while(q--){
        int *tBuk=new int[27]();
        cin >> s2;
        int ans=0;
        for(i=0; i<s2.length(); i++){
            tBuk[s2[i]-'a']++;
        }
        for(i=0; i<27; i++){
            if(tBuk[i]>0){
                ans=max(ans, vec[i][tBuk[i]-1]);
            }
        }
        cout << ans << "\n";
	}
    return 0;
}
