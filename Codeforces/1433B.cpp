// Problem : B. Yet Another Bookshelf
// Contest : Codeforces - Codeforces Round #677 (Div. 3)
// URL : https://codeforces.com/contest/1433/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct Segment{
	int l, r;
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n, v;
    	cin >> n;
    	int start=-1;
    	vector<Segment> segments;
    	for(int i=0; i<n; i++){
    		cin >> v;
    		if(v==0 && start!=-1){
    			segments.push_back({start, i-1});
    			start=-1;
    		}
    		else if(v==1 && start==-1) start=i;
    		if(start!=-1 && i==n-1) segments.push_back({start, i});
    	}
    	int ans=0;
    	while(segments.size()>2){
    		auto s1=segments[0];
    		auto s2=segments[1];
    		debug cout << "From " << s1.r << " to " << s2.l << "\n";
    		while(s1.r<s2.l-1){
    			s1.r++;
    			ans++;
    		}
    		debug cout << "Now we have: " << ans << "\n";
    		segments.erase(segments.begin());
    		s1=segments[segments.size()-2];
    		s2=segments[segments.size()-1];
    		debug cout << "From " << s1.r << " to " << s2.l << "\n";
    		while(s1.r+1<s2.l){
    			s2.l--;
    			ans++;
    		}
    		debug cout << "Now we have: " << ans << "\n";
    		segments.pop_back();
    	}
    	if(segments.size()==2){
    		ans+=segments[1].l-segments[0].r-1;
    	}
    	cout << ans << "\n";
    }
    return 0;
}