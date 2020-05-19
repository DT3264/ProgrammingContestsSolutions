#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> nums(n);
        map<int, int> cont;
        map<int, int> indexOf;
        for(int &x : nums) cin >> x;
        int actAns=0, bestAns=0;
        int start=0;
        for(int i=0; i<n; i++){
            int val=nums[i];
            int valCont=cont[val]++;
            if(valCont>0){
                int lastIndex=indexOf[val];
                int stopInd=max(start, indexOf[val]);
                for(int j=start; j<stopInd; j++){
                    indexOf[nums[j]]=stopInd;
                    cont[nums[j]]=0;
                }
                start=stopInd+1;
            }
            actAns=i-start+1;
            bestAns=max(actAns, bestAns);
            indexOf[val]=i;
        }
        cout << bestAns << "\n";
    }
    return 0;
}
