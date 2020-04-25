#include<bits/stdc++.h>
using namespace std;
struct Val{
    int val;
    int left;
    int right;
};
vector<Val> vec;
int getLeft(int val){
    if(val==-1){
        return -1;
    }
    if(vec[val].val==-1){
        vec[val].left=getLeft(vec[val].left);
        return vec[val].left;
    }
    else{
        return vec[val].val;
    }
}
int getRight(int val){
    if(val==-1){
        return -1;
    }
    if(vec[val].val==-1){
        vec[val].right=getRight(vec[val].right);
        return vec[val].right;
    }
    else{
        return vec[val].val;
    }
}
int main(){
    //freopen("in.txt", "right", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n, m, u, v;
    while(cin >> n >> m){
        if(n==0 && m==0)break;
        vec.clear();
        vec.push_back({0, -1, -1});
        vec.push_back({1, -1, n>1 ? 2 : -1});
        for(int i=2; i<n; i++) vec.push_back({i, i-1, i+1});
        if(n>=2){
            vec.push_back({n, n-1, -1});
        }
        //for(auto x : vec) cout << x.val << ": " << x.left << ", " << x.right << "\n";
        for(int i=0; i<m; i++){
            cin >> u >> v;
            vec[u].val=-1;
            vec[v].val=-1;
            int left=getLeft(u);
            int right=getRight(v);
            for(int j=u; j<=v; j++){
                vec[j].val=-1;
                vec[j].left=left;
                vec[j].right=right;
            }
            //cout << "*" << left << "* - *" << right << "*\n";
            if(vec.size()==0){
                cout << "* *\n";
            }
            else{
                if(left==-1){
                    cout << "* ";
                }
                else{
                    cout << left << " ";
                }
                if(right==-1){
                    cout << "*\n";
                }
                else{
                    cout << right << "\n";
                }
            }
        }
        cout << "-\n";
    }
	return 0;

}
