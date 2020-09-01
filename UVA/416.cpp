
// Problem : 416 - LED Test
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=357
// Memory Limit : 32 MB
// Time Limit : 3000 ms
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
struct Digit{
	string num;
	set<int> nums;
};
vector<Digit> digits;
vector<string> nums={
	"YYYYYYN",
	"NYYNNNN",
	"YYNYYNY",
	"YYYYNNY",
	"NYYNNYY",
	"YNYYNYY",
	"YNYYYYY",
	"YYYNNNN",
	"YYYYYYY",
	"YYYYNYY"
};
bool canBeOn(int n, string &num, string &badLeds){
	for(int i=0; i<num.size(); i++){
		//Invalid turn on
		if(num[i]=='Y' && badLeds[i]=='1') return false;
	}
	return true;
}
void burnLeds(int n, string &num, string &badLeds){
	for(int i=0; i<nums[n].size(); i++){
		//Turned on but failed
		if(nums[n][i]=='Y' && num[i]=='N'){
			badLeds[i]='1';
		}
	}
}

bool canBe(int n, string &str){
	for(int i=0; i<nums[n].size(); i++){
		if(nums[n][i]=='N' && str[i]=='N') continue;
		else if(nums[n][i]=='N' && str[i]=='Y') return false;
	}
	return true;
}
int countDown(int pos, int num, string burnedLeds){
	if(pos==digits.size()) return true;
	if(num<0) return false;
	int actAns=0;
	if(digits[pos].nums.count(num) && canBeOn(num, digits[pos].num, burnedLeds)){
		burnLeds(num, digits[pos].num, burnedLeds);
		actAns=max(actAns, countDown(pos+1, num-1, burnedLeds));
	}
	return actAns;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n;
    while(cin >> n && n!=0){
    	digits=vector<Digit>(n);
    	for(Digit &d : digits){
    		cin >> d.num;
    		for(int i=0; i<=9; i++){
    			if(canBe(i, d.num)){
    				d.nums.insert(i);
    			}
    		}
    	}
    	int found=0;
    	for(int i=9; i>=0 && !found; i--){
    		if(digits[0].nums.count(i)){
    			string burnedLeds="00000000";
    			burnLeds(i, digits[0].num, burnedLeds);
    			//cout << "Empezando con " << i << "\n";
    			found=max(found, countDown(1, i-1, burnedLeds));
    		}
    	}
    	cout << (!found ? "MIS":"") << "MATCH\n";
    }
    return 0;
}
