#include <bits/stdc++.h>
using namespace std;
int n, l, k;
string s;
vector<string> ans;
int cnt[150];
void findKthWord(){
    int t=1;
    char c='a';
    while(c<='z'){
        if(cnt[c]>k-t){
            for(int i=t; i<=k; i++){
                ans[i]+=c;
            }
            cnt[c]-=k-t+1;
            if(ans[k].size()==l) return;
        }
        else if(cnt[c]>0){
            for(int i=t; i<t+cnt[c]; i++){
                ans[i]+=c;
            }
            t+=cnt[c];
            cnt[c]=0;
        }
        else if(cnt[c]==0){
            c++;
        }
    }
}
void printAns(){
    for(int i=1; i<=n; i++){
        cout << ans[i] << "\n";
    }
}
int main(){
    int i, j;
    scanf("%d%d%d", &n, &l, &k);
    cin >> s;
    for(i=0; i<s.size(); i++){
        cnt[s[i]]++;
    }
    for(i=0; i<=n; i++){
        ans.push_back("");
    }
    findKthWord();
    char c = 'z';
    for(i=0; i<l; i++){
        for(j=n; j>k; j--){
            while(cnt[c]==0) c--;
            ans[j]+=c;
            cnt[c]--;
        }
    }
    for(i=k-1; i>=1; i--){
        while(ans[i].size()!=l){
            while(cnt[c]==0)c--;
            ans[i]+=c;
            cnt[c]--;
        }
    }
    printAns();
}
