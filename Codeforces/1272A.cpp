#include<bits/stdc++.h>
using namespace std;
long long arr[3];
long long sw[3];
long long minN;
void tryComb(int pos){
    if(pos==3){
        long long n1 = arr[0]+sw[0];
        long long n2 = arr[1]+sw[1];
        long long n3 = arr[2]+sw[2];
        long long act = abs(n1-n2)+abs(n2-n3)+abs(n1-n3);
        minN=min(minN, act);
        return;
    }
    sw[pos]=-1;
    tryComb(pos+1);
    sw[pos]=1;
    tryComb(pos+1);
    sw[pos]=0;
    tryComb(pos+1);
}
int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> arr[0] >> arr[1] >> arr[2];
        memset(sw, 0, sizeof(sw));
        minN = 1e12;
        tryComb(0);
        cout << minN << "\n";
    }
}
