#include<stdio.h>
int arr[100];

int part(int arr[], int left, int right, int piv){
    while(left<=right){
        while(arr[left]<piv){
            left++;
        }
        while(arr[right]>piv){
            right--;
        }
        if(left<=right){
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
    }
    return left;
}

void quickSort(int arr[], int left, int right){
    if(left<right){
        int piv=arr[(left+right)/2];
        int pos = part(arr, left, right, piv);
        quickSort(arr, left, pos-1);
        quickSort(arr, pos, right);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n-1);
    int left = 0;
    int right = n-1;
    int him=0;
    int me=0;
    int coins=0;
    while(left<=right){
        me+=arr[right--];
        coins++;
        while(left<=right && him<me){
            him+=arr[left++];
        }
    }
    if(him>=me){
        left--;
        him-=arr[left];
        me+=arr[left];
        coins++;
    }
    printf("%d", coins);
}
