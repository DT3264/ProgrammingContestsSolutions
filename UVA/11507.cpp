#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n && n!=0){
        string pos="+x", mov;
        for(int i=0; i<n-1; i++){
            cin >> mov;
            if(mov=="No"){
                continue;
            }
            if(pos=="+x"){
                pos=mov;
            }
            else if(pos=="-x"){
                pos=mov;
                pos[0] = (pos[0]=='+' ? '-' : '+');
            }
            else if(pos=="+z" && mov=="+z"){
                pos="-x";
            }
            else if(pos=="+z" && mov=="-z"){
                pos="+x";
            }
            else if(pos=="-z" && mov=="+z"){
                pos="+x";
            }
            else if(pos=="-z" && mov=="-z"){
                pos="-x";
            }
            else if(pos=="+y" && mov=="+y"){
                pos="-x";
            }
            else if(pos=="+y" && mov=="-y"){
                pos="+x";
            }
            else if(pos=="-y" && mov=="-y"){
                pos="-x";
            }
            else if(pos=="-y" && mov=="+y"){
                pos="+x";
            }
            //cout << i << " - " << pos << "\n";
        }
        cout << pos << "\n";
    }
	return 0;
}
