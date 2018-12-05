#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long n, m, a;
    long long tN=0, tM=0;
    long long cntN=0, cntM=0;
    long long total;
    cin >> n >> m >> a;
    tN = n/a;
    tM = m/a;
    if(a*tN<n)
        tN++;
    if(a*tM<m)
        tM++;
    total = tN*tM;
    cout << total;
    return 0;
}
