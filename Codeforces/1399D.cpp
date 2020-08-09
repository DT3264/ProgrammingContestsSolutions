
// Problem : D. Binary String To Subsequences
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi anstor<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int actID=1;
int CAN_ONE=1;
int CAN_ZERO=2;
struct Seq{
	int id;
	char right;
	int state;
	void setState(){
		if(right=='0') state=CAN_ONE;
		if(right=='1') state=CAN_ZERO;
	}
	void add(char &c){
		if(right!='0'){
			right='0';
		}
		else if(right!='1'){
			right='1';
		}
		setState();
	}
};
queue<Seq> canOne, canZero, canBoth;
void addSeq(Seq actSeq){
	if(actSeq.state==CAN_ZERO) canZero.push(actSeq);
    else if(actSeq.state==CAN_ONE) canOne.push(actSeq);
    else canBoth.push(actSeq);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	string str;
    	vector<int> ans;
    	canOne=queue<Seq>();
    	canZero=queue<Seq>();
    	canBoth=queue<Seq>();
    	cin >> n >> str;
    	Seq actSeq;
    	actID=1;
    	for(int i=0; i<n; i++){
    		debug cout << str[i] << " ";
    		bool added=false;
			if(canBoth.size()>0){
				actSeq=canBoth.front();
				canBoth.pop();
				actSeq.add(str[i]);
				ans.push_back(actSeq.id);
				addSeq(actSeq);
				added=true;
			}
			else if(canOne.size()>0  && str[i]=='1'){
				actSeq=canOne.front();
				canOne.pop();
				actSeq.add(str[i]);
				ans.push_back(actSeq.id);
				addSeq(actSeq);
				added=true;
			}
			else if(canZero.size()>0 && str[i]=='0'){
				actSeq=canZero.front();
				canZero.pop();
				actSeq.add(str[i]);
				ans.push_back(actSeq.id);
				addSeq(actSeq);
				added=true;
			}
			else{
				ans.push_back(actID);
				if(str[i]=='0'){
					debug cout << "To one\n";
					canOne.push({actID++, str[i], CAN_ONE});	
				}
				else{
					debug cout << "To zero\n";
					canZero.push({actID++, str[i], CAN_ZERO});	
				}
			}
    	}
    	cout << actID-1 << "\n";
    	for(int &x : ans) cout << x << " ";
    	cout << "\n";
    }
    return 0;
}
