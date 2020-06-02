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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll cases;
    cin >> cases;
    while(cases--){
        int b, sg, sb, t;
        cin >> b >> sg >> sb;
        priority_queue<int> green, blue;
        priority_queue<int> tempGreen, tempBlue;
        for(int i=0; i<sg; i++){
            cin >> t;
            green.push(t);
        }
        for(int i=0; i<sb; i++){
            cin >> t;
            blue.push(t);
        }
        while(!green.empty() && !blue.empty()){
            for(int i=0; i<b && !green.empty() && !blue.empty(); i++){
                tempGreen.push(green.top());
                tempBlue.push(blue.top());
                green.pop();
                blue.pop();
            }
            while(!tempGreen.empty() && !tempBlue.empty()){
                int tGreen=tempGreen.top();
                int tBlue=tempBlue.top();
                tempGreen.pop();
                tempBlue.pop();
                if(tGreen>tBlue){
                    green.push(tGreen-tBlue);
                }
                else if(tGreen==tBlue){
                    ///Nada
                }
                else if(tGreen<tBlue){
                    blue.push(tBlue-tGreen);
                }
            }
            while(!tempGreen.empty()){
                green.push(tempGreen.top());
                tempGreen.pop();
            }
            while(!tempBlue.empty()){
                blue.push(tempBlue.top());
                tempBlue.pop();
            }
        }
        if(green.empty() && blue.empty()){
            cout << "green and blue died\n";
        }
        else if(!green.empty() && blue.empty()){
            cout << "green wins\n";
            while(!green.empty()){
                cout << green.top() << "\n";
                green.pop();
            }
        }
        else if(green.empty() && !blue.empty()){
            cout << "blue wins\n";
            while(!blue.empty()){
                cout << blue.top() << "\n";
                blue.pop();
            }
        }
        if(cases>0)
        cout << "\n";
    }
    return 0;
}
