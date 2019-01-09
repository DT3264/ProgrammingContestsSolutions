#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<int> powersOf2;
int i, n, res;
int main(){
    scanf("%d", &n);
    while(pow(2, i)<=1e9){
        powersOf2.push_back(pow(2, i++));
    }
    while(n>0){
        for(i=powersOf2.size()-1; i>=0; i--){
            if(powersOf2[i]<=n){
                n-=powersOf2[i];
                res++;
                i=-1;
            }
        }
    }
    printf("%d", res);
    return 0;
}
