    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int n, h, m, t;
    	cin >> n;
    	while(n--){
    		t=0;
    		cin >> h >> m;
    		if(m<60){
    			t+=60-m;
    			h++;
    		}
    		if(h<24){
    			t+=(24-h)*60;
    		}
    		cout << t << endl;
    	}
    	return 0;
    }