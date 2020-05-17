#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll cases;
    cin >> cases;
    while(cases--){
        int n, sSize, qSize;
        int totalCargos=0;
        stack<int> mainS;
        cin >> n >> sSize >> qSize;
        vector<queue<int>> vec;
        vec.push_back(queue<int>());
        //cout << "Leyendo cargos\n";
        for(int i=1; i<=n; i++){
            queue<int> actQ;
            int cargos, actCargo;
            cin >> cargos;
            totalCargos+=cargos;
            while(cargos--){
                cin >> actCargo;
                actQ.push(actCargo);
            }
            vec.push_back(actQ);
        }
        //cout << "Cargos leidos\n";
        //cout << vec.size() << "\n";
        int time=0;
        int actPos=1;
        while(totalCargos>0){
            while(!mainS.empty()){
                if(mainS.top()==actPos){
                    ///On destination
                    totalCargos--;
                }
                else if(vec[actPos].size()<qSize){
                    ///Not on destination
                    vec[actPos].push(mainS.top());
                }
                else{
                    break;
                }
                mainS.pop();
                time++;
            }
            while(!vec[actPos].empty() && mainS.size()<sSize){
                ///Up again
                mainS.push(vec[actPos].front());
                vec[actPos].pop();
                time++;
            }
            actPos++;
            if(totalCargos>0){
                time+=2;
            }
            if(actPos==n+1){
                actPos=1;
            }
            //system("pause");
        }
        cout << time << "\n";
    }
    return 0;
}
