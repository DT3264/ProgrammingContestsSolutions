#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
#define noDebug if(!printDebug)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
int ans[51];
bool used[10];
void test(int pos){
    if(pos>9){
        int sum=0;
        string str;
        for(int i=0; i<10; i++){
            if(used[i]){
                sum+=i;
                str+=i+'0';
            }
        }
        if(str.size()==0) return;
        int num=stoi(str);
        if(sum<=50 && ans[sum]!=-1 && num<ans[sum]) ans[sum]=num;
        if(sum<=50 && ans[sum]==-1) ans[sum]=num;
        return;
    }
    used[pos]=false;
    test(pos+1);
    used[pos]=true;
    test(pos+1);
}
int main(){
    memset(ans, -1, sizeof(ans));
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    test(1);
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
	    cout << ans[n] << "\n";
    }
    return 0;
}
