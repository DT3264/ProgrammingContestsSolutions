#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<int>
#define pii pair<int, int>
#define ll long long
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string initialString;
    while(cin >> initialString){
        if(initialString=="#") break;
        string nextString=initialString;
        next_permutation(nextString.begin(), nextString.end());
        cout << (initialString < nextString ? nextString : "No Successor") << "\n";
    }
    return 0;
}
