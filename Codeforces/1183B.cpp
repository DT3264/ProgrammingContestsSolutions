#include <bits/stdc++.h>
using namespace std;
int *arr;
int canEqualizeToX(int x, int n, int k){
    for(int i=0; i<n; i++){
        if(arr[i]<x){
            if(x-arr[i]>k){
                return 2;
            }
        }
        else if(arr[i]>x){
            if(arr[i]-x>k){
                return 3;
            }
        }
    }
    return 1;
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int q;
    scanf("%d", &q);
    while(q--){
        int n, k, i;
        arr=new int[100];
        scanf("%d%d", &n, &k);
        for(i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+n);
        int left = arr[0]-k;
        if(left<1) left=1;
        int right=arr[n-1]+k;
        int actualAns=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            //printf("trying with %d, left: %d, right: %d\n", mid, left, right);
            int test=canEqualizeToX(mid, n, k);
            if(test==1){
                left=mid+1;
                actualAns=mid;
            }
            else if(test==3){
                left=mid+1;
            }
            else if(test==2){
                right=mid-1;
            }
        }
        cout << actualAns << endl;
    }
    return 0;
}