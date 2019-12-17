#include<bits/stdc++.h>
using namespace std;
int focos[100];
int main(){
    double x1, y1, x2, y2;
    double n, k;
    double distActual=0;
    cin >> n >> k;
    cin >> x1 >> y1;
    for(int i=1; i<n; i++){
        cin >> x2 >> y2;
        distActual+=sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
        x1=x2;
        y1=y2;
    }
    cout << setprecision(9) << fixed << k*(distActual/50) << endl;
}
