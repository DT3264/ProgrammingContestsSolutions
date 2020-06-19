#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    string str;
    while(getline(cin, str) && str!="END"){
        vector<string> vec;
        vec.push_back(str);
        vec.push_back(to_string(str.size()));
        int ind=-1;
        while(vec[vec.size()-2]!=vec.back()){
            vec.push_back(to_string(vec.back().size()));
        }
        cout << vec.size()-1 << "\n";
    }
    return 0;

}
