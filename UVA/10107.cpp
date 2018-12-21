#include<stdio.h>
#include<algorithm>
int nums[10000];
using namespace std;
int main(){
    int numPos = 0;
    while(scanf("%d", &nums[numPos])!=EOF){
        sort(nums, nums+numPos+1);
        numPos++;
        if(numPos%2==0) printf("%d\n", (nums[(numPos/2)-1]+nums[numPos/2])/2);
        else printf("%d\n", nums[numPos/2]);
    }

    return 0;
}
