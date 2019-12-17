#include<bits/stdc++.h>
using namespace std;
int main(){
    double n1, n2, len;
    cin >> len >> n1 >> n2;
    double left=0, right=len;
    double ans;
    for(int i=0; i<20; i++){
        double mid=(left+right)/2;
        double p1=mid/n1;
        double p2=(len-mid)/n2;
        if(p1<p2){
            left=mid+0.0001;
        }
        else if(p1>p2){
            right=mid-0.0001;
        }
        ans=mid;
    }
    cout << ans << endl;
}
