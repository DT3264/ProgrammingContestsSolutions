#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pss pair<string, string>
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, actCase=1;
    cin >> n;
    cin.ignore();
    string basura;
    getline(cin, basura);
    while(n--){
        if(actCase++>1) cout << "\n";
        string str;
        vector<pss> vec;
        while(getline(cin, str) && str!=""){
            string customStr="";
            for(char c : str){
                if(c!=' '){
                    customStr+=c;
                }
            }
            sort(customStr.begin(), customStr.end());
            vec.push_back({str, customStr});
        }
        sort(vec.begin(), vec.end(), [](const pss &p1, const pss &p2){
            return p1.f < p2.f;
        });
        for(int i=0; i<vec.size(); i++){
            for(int j=i+1; j<vec.size(); j++){
                if(vec[i].second == vec[j].second){
                    cout << min(vec[i].f, vec[j].f) << " = " << max(vec[i].f, vec[j].f) << "\n";
                }
            }
        }
    }
	return 0;
}
