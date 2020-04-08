#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int main(){
    int q, a, b, cases=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> str){
        cout<< "Case " << cases++ << ":\n";
        arr[str.size()-1]=str.size()-1;
        for(int i=str.size()-2; i>=0; i--){
            if(str[i+1]==str[i]){
                arr[i]=arr[i+1];
            }
            else{
                arr[i]=i;
            }
        }
        cin >> q;
        for(int i=0; i<q; i++){
            cin >> a >> b;
            cout << (arr[a]==arr[b] ? "Yes" : "No") << "\n";
        }
    }
	return 0;
}
