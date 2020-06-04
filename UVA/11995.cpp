#include<bits/stdc++.h>
#define f first
//#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
int main(){
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, t, op;
    while(cin >> n){
        priority_queue<int> pq;
        stack<int> s;
        queue<int> q;
        bool canPQ=true, canS=true, canQ=true;
        for(int i=0; i<n; i++){
            cin >> op >> t;
            if(op==1){
                pq.push(t);
                s.push(t);
                q.push(t);
            }
            else if(op==2){
                if(pq.size()>0){
                    if(pq.top()!=t){
                        canPQ=false;
                    }
                    else{
                        pq.pop();
                    }
                }
                else{
                    canPQ=false;
                }
                if(s.size()>0){
                    if(s.top()!=t){
                        canS=false;
                    }
                    else{
                        s.pop();
                    }
                }
                else{
                    canS=false;
                }
                if(q.size()>0){
                    if(q.front()!=t){
                        canQ=false;
                    }
                    else{
                        q.pop();
                    }
                }
                else{
                    canQ=false;
                }
            }
        }
        if(canPQ && canQ+canS==0){
            cout << "priority queue";
        }
        else if(canQ && canPQ+canS==0){
            cout << "queue";
        }
        else if(canS && canPQ+canQ==0){
            cout << "stack";
        }
        else if(canS+canPQ+canQ>0){
            cout << "not sure";
        }
        else{
            cout << "impossible";
        }
        cout << "\n";
    }
    return 0;
}
