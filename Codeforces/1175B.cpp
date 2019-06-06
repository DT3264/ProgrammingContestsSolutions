#include <bits/stdc++.h>
using namespace std;
stack<long long> op;
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string s;
    int n, i;
    unsigned int x=0;
    unsigned int forN=1, addToFor=1;
    unsigned int contOverflow=0;
    bool overflow=false;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> s;
        //cout << "x: " << x << " - for(" << forN << ")" << endl;
        if(s=="add"){
            if(contOverflow>0){
                overflow=true;
            }
            if(!overflow){
                if(__builtin_uadd_overflow(x, forN, &x)){
                    overflow=true;
                }
                if(x>pow(2, 32)){
                    overflow=true;
                }

            }
        }
        else if(s=="for"){
            cin >> addToFor;
            int lastVal=forN;
            if(contOverflow>0){
                contOverflow++;
                continue;
            }
            if(__builtin_umul_overflow(forN, addToFor, &forN)){
                forN=lastVal;
                contOverflow++;
            }
            else{
                op.push(addToFor);
            }
        }
        else if(s=="end"){
            if(contOverflow>0){
                contOverflow--;
            }
            else{
                forN/=op.top();
                op.pop();
            }
        }
    }
    if(!overflow){
        cout << x;
    }
    else{
        cout << "OVERFLOW!!!";
    }
}
