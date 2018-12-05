#include<stdio.h>

int arr[101];
int nums[101];
int buk[101];
int contN;

int main(){
    int n, k, i;
    scanf("%d%d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(buk[arr[i]]++==0){
            nums[contN++]=arr[i];
        }
    }
    int posibleUt=0, stolen=0;
    for(i=0; i<contN; i++) if(posibleUt<buk[nums[i]]) posibleUt=buk[nums[i]];
    if(posibleUt%k!=0)///If the utensiles doesn't match with the king's guests
    posibleUt=posibleUt+k-(posibleUt%k);///Go to the next k and remove the exceded
    for(i=0; i<contN; i++) stolen+=posibleUt-buk[nums[i]];///and count the stolen
    printf("%d", stolen);
    return 0;
}



