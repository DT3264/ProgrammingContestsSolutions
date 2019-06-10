#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    long long m;
    scanf("%d", &n);
    while(n--){
        scanf("%lld", &m);
        ll steps=0;
        ll lastM=-1;
        while(m>1){
            if(m%5==0){
                m=(4*m)/5;
                steps++;
            }
            if(m%3==0){
                m=(2*m)/3;
                steps++;
            }
            if(m%2==0){
                m=m/2;
                steps++;
            }
            if(lastM==m){
                break;
            }
            lastM=m;
        }
        if(m!=1){
            steps=-1;
        }
        printf("%lld\n", steps);
    }
}
