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
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int x, y, z;
    	cin >> x >> y >> z;
    	int a=-1, b=-1, c=-1;
    	if(x==y){
    		if(x!=z){
    			//Dos
    			a=x;
    			b=z, c=z;
    		}
    		else{
    			//Tres
    			a=x, b=x, c=x;
    		}
    	}
    	else if(x==z){
  			//Dos
  			a=y, c=y;
  			b=x;
    	}
    	else if(y==z){
    		a=x, b=x;
    		c=y;
    	}
    	if(max(a, b)==x && max(a, c)==y && max(b, c)==z){
    		cout << "YES\n";
    		cout << a << " " << b << " " << c << "\n";
    	}
    	else{
    		cout << "NO\n";
    	}
    }
    return 0;
}
