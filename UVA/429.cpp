#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
template<class T>
using v=vector<T>;
int indexOf(v<string> &vec, string &str){
	// cout<<"Buscando " << str << endl;
	for(int i=0; i<vec.size(); i++){
		// cout << vec[i].size() << "  "  << str.size() <<endl;
		if(vec[i] == str) return i;
	}
	return -1;
}
int dist(string &s1, string &s2){
	if(s1.size() != s2.size()) return 0;
	int dist=0;
	for(int i=0; i<s1.size(); i++){
		dist += s1[i]!=s2[i];
	}
	return dist;
}
int main(){
    // printDebug=true;
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    string s;
    getline(cin, s);
	int n = stoi(s);
	int actCase=1;
    while(actCase<=n){
    	if(actCase++>1) cout << '\n';
    	v<string> words;
    	while(getline(cin,s) && s!="*"){
    		// cout << s << " " << s.size() <<  endl;
    		words.push_back(s);
    	}
    	// sort(words.begin(), words.end());
    	// cout << "Querys\n";
    	string s1, s2;
    	while(getline(cin, s) && s!= ""){
    		stringstream ss(s);
    		ss >> s1 >> s2;
    		int idx1=indexOf(words, s1);
    		int idx2=indexOf(words, s2);
    		// cout<< "ID1: " <<idx1<<endl;
    		// cout<< "ID2: " <<idx2<<endl;
    		int jumps=0;
    		queue<int> q;
    		q.push(idx1);
    		bool found=0;
    		// cout << "En " << words[idx1] << endl;
    		v<int> step(words.size(), -1);
    		step[idx1]=0;
    		while(!q.empty()){
    			int act = q.front();
    			q.pop();
    			if(found) continue;
    			// cout << "En " << words[act] << endl;
    			for(int i=0; i<words.size(); i++){
    				// cout << "revisando " << i << endl;
    				if(words[i].size() != s1.size()) continue;
    				if(step[i] != -1) continue;
    				if(dist(words[act], words[i]) == 1){
    					step[i]=step[act]+1;
    					// cout << "Puede a " << words[i] << endl;
    					q.push(i);
    					if(i==idx2){
    						found=1;
    						i=words.size();
    					}
    				}
    			}
    		}
    		cout << s1 << " " << s2 << " " << step[idx2] << endl;
    	}
    }
    return 0;
}
