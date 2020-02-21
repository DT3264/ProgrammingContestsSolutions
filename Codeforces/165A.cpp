#include<bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
int n;
P arr[200];
bool isSuperCentral(P actualP){
    bool l=0, r=0, u=0, d=0;
    for(int i=0; i<n; i++){
        if(actualP.x==arr[i].x && actualP.y<arr[i].y){
            u=1;
        }
        if(actualP.x==arr[i].x && actualP.y>arr[i].y){
            d=1;
        }
        if(actualP.x<arr[i].x && actualP.y==arr[i].y){
            r=1;
        }
        if(actualP.x>arr[i].x && actualP.y==arr[i].y){
            l=1;
        }
    }
    return l && r && u && d;
}
int main(){
    int i, ans=0;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    for(i=0; i<n; i++){
        ans+=isSuperCentral(arr[i]);
    }
    cout << ans << endl;
return 0;
}
