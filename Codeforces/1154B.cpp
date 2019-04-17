#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int arr[100];
vector<int> nums;

void printAns(int &n){
    printf("%d", (n>=0 ? n : -1));
}

int main(){
    int i, n;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr+n);
    nums.push_back(arr[0]);
    for(i=1; i<n; i++){
        if(arr[i]!=arr[i-1]){
            nums.push_back(arr[i]);
        }
    }
    if(nums.size()>3){
        printf("-1");
    }
    else{
        int testN;
        if(nums.size()==1){
            printf("0");
        }
        else if(nums.size()==2){
            ///Test if the nums are left and right
            testN=(nums[1]-nums[0])/2;
            int a=nums[1]-testN, b=nums[0]+testN;
            if(a==b){
                printAns(testN);
            }
            else{///one of them is the center
                testN=nums[1]-nums[0];
                printAns(testN);
            }
        }
        else if(nums.size()==3){
            int testN=(nums[2]-nums[0])/2;
            int a=nums[2]-testN, b=nums[0]+testN;
            if(a==b && a==nums[1]){
                printAns(testN);
            }
            else{
                printf("-1");
            }
        }
    }
}