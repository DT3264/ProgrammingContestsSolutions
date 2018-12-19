#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
int n;
int remainBids;
int actualGCD;
int arr[100001];
map<int, int> mapa;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    gcd(b, a%b);
}
int split(int arr[], int left, int right, int piv){
    while(left<=right){
        while(arr[left]<piv){
            left++;
        }
        while(arr[right]>piv){
            right--;
        }
        if(left<=right){
            int temp = arr[left];
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
        int piv = arr[(left+right)/2];
        int mid = split(arr, left, right, piv);
        quickSort(arr, left, mid-1);
        quickSort(arr, mid, right);
    }
}

void loadMultiples(int x){
    if(x>arr[n-1] || remainBids==0 || mapa[x]==-1){
        return;
    }
	///If the val at [X] is not 0 and is not 1, 
	///then the val exist in the array, so we extract all the X of it
    if(mapa[x]!=0 && mapa[x]!=-1){
        remainBids-=mapa[x];
    }
	///Mark to know if we already steped on that X before
    mapa[x]=-1;
    loadMultiples(x*2);
    loadMultiples(x*3);
}


int main(){
    int i;
    scanf("%d", &n);
    remainBids=n;
	///As we read the numbers, we get the GCD of them
	///And also as a bucket we keep track of how many of each N are
    scanf("%d", &arr[0]);
    scanf("%d", &arr[1]);
    actualGCD = gcd(arr[0], arr[1]);
    mapa[arr[0]]++;
    mapa[arr[1]]++;
    for(i=2; i<n; i++){
        scanf("%d", &arr[i]);
        actualGCD = gcd(actualGCD, arr[i]);
        mapa[arr[i]]++;
    }
	///As part or learning sorts, instead of just getting the biggest number, 
	///I'll sort the array and grab the last number
    quickSort(arr, 0, n-1);
	///Then we load all the posible multiples by 2 and 3 from the GCD of all the numbers 
    loadMultiples(actualGCD);
	///If at least one bid remains
	///it means it wasn't multiple of the numbers and so, all numbers couldn't be reached
    printf("%s", (remainBids==0 ? "Yes" : "No"));
    return 0;
}
