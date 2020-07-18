#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
bool isGood(vector<int> &vec, int from){
	int left=from, right=vec.size()-1;
	int lastVal=0;
	while(left<=right){
		if(vec[left]<=vec[right]){
			if(vec[left]<lastVal) return false;
			lastVal=vec[left];
			left++;
		}
		else if(vec[right]<=vec[left]){
			if(vec[right]<lastVal) return false;
			lastVal=vec[right];
			right--;
		}
	}
	return true;
}
bool isSorted(vector<int> &vec){
	for(int i=1; i<vec.size(); i++){
		if(vec[i]<vec[i-1]) return false;
	}
	return true;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vector<int> vec(n);
    	for(int &x : vec) cin >> x;
    	int left=0, right=n-1;
    	int lastAns=-1;
    	if(isSorted(vec)){
    		cout << "0\n";
    		continue;
    	}
    	while(left<=right){
    		int mid=left+(right-left)/2;
    		bool can=isGood(vec, mid);
    		if(can){
    			lastAns=mid;
    			right=mid-1;
    		}
    		else{
    			left=mid+1;
    		}
    	}
    	cout << lastAns << "\n";
    }
    return 0;
}
