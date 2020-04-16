#include<bits/stdc++.h>
using namespace std;
vector<bool> used;
int findFrom(int from){
    for(int i=from; i<=52; i++){
        if(!used[i]) return i;
    }
    return -1;
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1(3), v2(2);
    while(cin >> v1[0]){
        used.assign(52+1, 0);
        int ans=-1;
        for(int i=1; i<3; i++) cin >> v1[i];
        for(int i=0; i<2; i++) cin >> v2[i];
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if(v1[0]==0) break;
        for(int x : v1) used[x]=1;
        for(int x : v2) used[x]=1;
        int x=0, y=0;
        for(int val : v1){
            if(val<v2[0]) x++;
            if(val<v2[1]) y++;
        }
        if(x+y==6){///3,3
            ans=findFrom(1);
        }
        else if(x==2 && y>=2){///2,3; 2,2
            ans=findFrom(v1[1]);
        }
        else if(x!=2 && y==3){///0,3; 1,3
            ans=findFrom(v1[2]);
        }
        cout << ans << "\n";
    }
	return 0;
}
