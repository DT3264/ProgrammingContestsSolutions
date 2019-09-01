#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, n;
    long long ans=0;
    string str;
    map<string, int> mapa;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        cin >> str;
        std::sort(str.begin(), str.end());
        mapa[str]++;
        if(mapa[str]>1){
            ans+=mapa[str]-1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
