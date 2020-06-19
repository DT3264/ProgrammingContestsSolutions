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
    int setN=1;
    while(getline(cin, str)){
        stringstream ss(str);
        vector<int> vec(36001, 0);
        int nums=0, t;
        int minT=1e9;
        while(ss >> t){
            minT=min(minT, t);
            nums++;
            int actT=0;
            while(actT<=3600){
                for(int i=actT; i<=actT+t-6; i++){
                    vec[i]++;
                }
                actT+=t*2;
            }
        }
        for(int i=0; i<minT*2; i++){
            vec[i]=0;
        }
        int seconds=-1;
        for(int i=0; i<=3600; i++){
            if(vec[i]==nums){
                seconds=i;
                break;
            }
        }
        int minutes=seconds/60;
        seconds-=minutes*60;
        if(seconds==-1){
            cout << "Set " << setN++ << " is unable to synch after one hour.\n";
        }
        else{
            cout << "Set " << setN++ << " synchs again at " << minutes << " minute(s) and " << seconds << " second(s) after all turning green.\n";
        }
    }
    return 0;

}
