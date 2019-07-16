#include "bits/stdc++.h"
using namespace std;
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int q, i;
	int bukS[27], bukT[27];
	scanf("%d", &q);
	char s[101], t[101], p[101];
	while(q--){
		scanf("%s%s%s", s, t, p);
		memset(bukS, 0, sizeof(bukS));
		memset(bukT, 0, sizeof(bukT));
		int sLen=strlen(s);
		int tLen=strlen(t);
		int pLen=strlen(p);
		for(i=0; i<sLen; i++){
			bukS[s[i]-'a']++;
		}
		for(i=0; i<pLen; i++){
			bukS[p[i]-'a']++;
		}
		for(i=0; i<tLen; i++){
			bukT[t[i]-'a']++;
		}
		bool ans=true;
		int sPos=0;
		for(i=0; i<tLen; i++){
			if(t[i]==s[sPos]){
				sPos++;
			}
		}
		ans=sLen==sPos;
		for(i=0; i<27 && ans; i++){
			if(bukS[i]<bukT[i]){
				ans=false;
			}
		}
		printf("%s\n", (ans ? "YES" : "NO"));
	}
	return 0;
}