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
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        vector<int> vec(3, 0);///0->MF, 1->MM, 2->FF
        getline(cin, str);
        stringstream ss(str);
        int tracks=0;
        while(ss >> str){
            tracks++;
            if(str=="MF" || str=="FM") vec[0]++;
            else if(str=="MM") vec[1]++;
            else if(str=="FF") vec[2]++;
        }
        int minN=min(vec[1], vec[2]);
        vec[1]-=minN;
        vec[2]-=minN;
        vec[0]+=minN;
        if(vec[0]>0 && vec[1]+vec[2]==0 && tracks>1) cout << "LOOP\n";
        else cout << "NO LOOP\n";
    }
    return 0;

}
