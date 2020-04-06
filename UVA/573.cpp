#include<iostream>
using namespace std;
int main(){
    double h, u, d, f;
    while(cin >> h >> u >> d >> f && (h!=0 && u!=0 && d!=0 && f!=0)){
        f=(u/100)*f;
        double day=1, h0=0, actDist=u, h1=0, h2=0;
        while(h0<h){
            h0=h2;
            h1=h0+max(actDist, 0.0);
            actDist-=f;
            h2=h1-d;
            if(h0<=0 && day!=1){
                if(h0<0) day--;
                cout << "failure on day " << day << "\n";
                break;
            }
            if(h1>h){
                cout << "success on day " << day << "\n";
                break;
            }
            day++;
        }
    }
    return 0;
}
