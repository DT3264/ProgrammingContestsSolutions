#include<bits/stdc++.h>
using namespace std;
struct par{
    int a;
    int b;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    deque<int> dq;
    int MAX = (1e5)+1;
    int n, q, i;
    long long t;
    int arr[MAX];
    par firstRound[MAX];
    par secondRound[MAX];
    cin >> n >> q;
    for(i=0; i<n; i++){
        cin >> t;
        dq.push_back(t);
    }
    for(i=0; i<n-1; i++){
        int a=dq.front();
        dq.pop_front();
        int b=dq.front();
        dq.pop_front();
        if(a>=b){
            dq.push_front(a);
            dq.push_back(b);
        }
        if(b>a){
            dq.push_front(b);
            dq.push_back(a);
        }
        firstRound[i]={a, b};
    }
    for(i=0; i<n; i++){
        int a=dq.front();
        dq.pop_front();
        int b=dq.front();
        dq.pop_front();
        if(a>=b){
            dq.push_front(a);
            dq.push_back(b);
        }
        if(b>a){
            dq.push_front(b);
            dq.push_back(a);
        }
        secondRound[i]={a, b};
    }
    for(i=0; i<q; i++){
        cin >> t;
        if(t<n){
            cout << firstRound[t-1].a << " " << firstRound[t-1].b << "\n";
        }
        else{
            t--;
            t%=(n-1);
            cout << secondRound[t].a << " " << secondRound[t].b << "\n";
        }
    }
    return 0;
}
