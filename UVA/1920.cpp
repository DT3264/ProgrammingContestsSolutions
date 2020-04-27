#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<int>
#define pii pair<int, int>
#define ll long long
using namespace std;
void nextDir(int &dir){
    dir++;
    if(dir==5) dir=1;
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dir=1;///1:Up; 2:Right; 3:Down; 4:Left;
    ll n, m;
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        pii pos={(n+1)/2, (n+1)/2};
        ll val=1;
        ll potencia=1;
        dir=3;
        int posibleMovs=0;
        int actMovs=0;
        while(potencia*potencia<m){
            //*/
            potencia+=2;
            pos.f++;
            pos.s++;
            posibleMovs+=2;
        }
        //cout << "Start:\n";
        //cout << pos.f << "," << pos.s << "\n";
        val=potencia*potencia;
        while(val!=m){
            if(dir==1){///Up
                pos.f++;
            }
            else if(dir==2){///Right
                pos.s++;
            }
            else if(dir==3){///Down
                pos.f--;
            }
            else if(dir==4){///Left
                pos.s--;
            }
            val--;
            actMovs++;
            if(actMovs==posibleMovs){
                actMovs=0;
                nextDir(dir);
            }
            //cout << val << " -> " << pos.f << ", " << pos.s << "\n";
        }
        cout << "Line = " << pos.f << ", column = " << pos.s << ".\n";
    }
    return 0;
}
