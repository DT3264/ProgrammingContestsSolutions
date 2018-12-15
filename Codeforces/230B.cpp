///Knowing that the numbers with 3 divisors are the square of the primes
///here are preloaded the primes up to 1,000,000 and their squares in a vector,
///then for each n we read, with a binary search we look for n, and if it exist, "YES" is printed, otherwise "NO"
#include<stdio.h>
#include<vector>
#include<math.h>
#include<iostream>
using namespace std;
bool used[1000001];
vector<long long> tPrimes;
void loadCrib(){
    used[0]=used[1]=1;
    for(long long i=2; i<=1000000; (i==2 ? i++ : i+=2)){
        if(!used[i]){
            tPrimes.push_back(i*i);
            for(long long j=i*i; j<=1000000; j+=i){
                used[j]=true;
            }
        }
    }
}

int main(){
    ///ios::sync_with_stdio(false);
    loadCrib();
    int i, n;
    cin >> n;
    long long t;
    for(i=0; i<n; i++){
        cin >> t;
        int left=0;
        int right=tPrimes.size()-1;
        int mid;
        bool ans=false;
        while(left<=right){
            mid=(left+right)/2;
            if(tPrimes[mid]==t){
                ans=true;
                break;
            }
            else if(tPrimes[mid]>t) right=mid-1;
            else if(tPrimes[mid]<t) left=mid+1;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}