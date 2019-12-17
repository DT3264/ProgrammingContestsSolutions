#include<bits/stdc++.h>
struct num{
    int num;
    int index;
};
using namespace std;
int main(){
    int n, i;
    num nums[2001];
    int ans[2001];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &nums[i].num);
        nums[i].index=i;
    }
    sort(nums, nums+n, [](const num &n1, const num &n2){
         return n1.num>n2.num;
    });
    int pos=1;
    ans[nums[0].index]=pos;
    for(i=1; i<n; i++){
        if(nums[i].num!=nums[i-1].num){
            pos=i+1;
        }
        ans[nums[i].index]=pos;
    }
    for(i=0; i<n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}
