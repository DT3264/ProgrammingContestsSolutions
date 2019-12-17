#include<bits/stdc++.h>
using namespace std;
int main(){
    long long k, n, w;
    cin >> k >> n >> w;
    long long total = (w*(w+1))/2;
    long long price = total*k;
    long long toBorrow = price-n;
    cout << (toBorrow > 0 ? toBorrow : 0) << endl;
    return 0;
}
