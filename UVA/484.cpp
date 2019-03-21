#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int, int> mapa;
vector<int> nums;
int main(){
    int n;
    while(cin >> n){
        if(mapa[n]==0){
            nums.push_back(n);
        }
        mapa[n]++;
    }
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " " << mapa[nums[i]] << "\n";
    }
}
