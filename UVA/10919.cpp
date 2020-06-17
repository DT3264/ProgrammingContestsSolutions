#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, m, t;
    while(cin >> n >> m){
        map<int, bool> courseList;
        for(int i=0; i<n; i++){
            cin >> t;
            courseList[t]=true;
        }
        int courses, course, minT;
        bool can=true;
        for(int i=0; i<m; i++){
            cin >> courses >> minT;
            for(int j=0; j<courses; j++){
                cin >> course;
                if(courseList[course]) minT--;
            }
            if(minT>0) can=false;
        }
        cout << (can ? "yes" : "no") << "\n";
    }
    return 0;

}
