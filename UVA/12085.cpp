#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, j;
    int caseN=1;
    while(cin >> n && n!=0){
        cout << "Case " << caseN++ << ":\n";
        vector<string> vec(n);
        for(string &x : vec){
            cin >> x;
        }
        sort(vec.begin(), vec.end());
        int startP=0;
        int endP=0;
        for(i=1; i<vec.size(); i++){
            if(stoi(vec[i])==stoi(vec[i-1])+1){
                endP++;
            }
            else{
                if(startP==endP){
                    cout << vec[startP] << "\n";
                }
                else{
                    cout << vec[startP] << "-";
                    for(j=0; j<vec[startP].size(); j++){
                        //cout << vec[startP][j] << "?=" << vec[endP][j] << "\n";
                        if(vec[startP][j]!=vec[endP][j]){
                            while(j<vec[endP].size()) cout << vec[endP][j++];
                        }
                    }
                    cout << "\n";
                }
                startP=i;
                endP=i;
            }
        }
        if(endP==n-1){
            if(startP==endP){
                cout << vec[startP] << "\n";
            }
            else{
                cout << vec[startP] << "-";
                for(j=0; j<vec[startP].size(); j++){
                    //cout << vec[startP][j] << "?=" << vec[endP][j] << "\n";
                    if(vec[startP][j]!=vec[endP][j]){
                        while(j<vec[endP].size()) cout << vec[endP][j++];
                    }
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
	return 0;
}
