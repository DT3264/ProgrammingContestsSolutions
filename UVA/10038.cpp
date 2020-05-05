#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<int>
#define pii pair<int, int>
#define ll long long
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    while(cin >> n){
            if(n==0 ) break;
        vector<int> vec(n);
        vector<int> vec2;
        for(int &x : vec){
            cin >> x;
        }
        bool jolly=true;
        if(vec.size()>1){
            for(int i=0; i<n-1; i++){
                vec2.push_back(abs(vec[i+1]-vec[i]));
            }
            sort(vec2.begin(), vec2.end());
            if(vec2[0]!=1) jolly=false;
            for(int i=1; i<vec2.size(); i++){
                if(vec2[i]!=vec2[i-1]+1) jolly=false;
            }
        }
        cout << (jolly ? "Jolly" : "Not jolly") << "\n";
    }
    return 0;
}
