#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int arr[27]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, m;
    string str;
    cin >> n;
    cin.ignore();
    while(n--){
        int repeated=0;
        map<string, int> mapa;
        getline(cin, str);
        cin >> m;
        //cin.ignore();
        getline(cin, str);
        while(m--){
            string num="";
            getline(cin, str);
            for(char &c : str){
                if(c>='A' && c<='Z'){
                    num+=arr[c-'A']+'0';
                }
                else if(c>='0' && c<='9'){
                    num+=c;
                }
                if(num.size()==3) num+='-';
            }
            if(mapa[num]==1){
                repeated++;
            }
            mapa[num]++;
            //cout << m << "-" << num << "\n";
        }
        if(repeated==0){
            cout << "No duplicates.\n";
        }
        else{
            for(auto &p : mapa){
                if(p.s>1) cout << p.f << " " << p.s << "\n";
            }
        }
        if(n>0) cout << "\n";

    }
    return 0;

}
