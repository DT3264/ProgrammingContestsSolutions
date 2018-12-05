#include<stdio.h>
int main (){
    int n;
    int arr[5] = {100, 20, 10, 5, 1};
    scanf("%d", &n);
    char t;
    int san2Seat=0, seat2San=0;
    char actualCity, nextCity;
    scanf(" %c", &actualCity);
    for(int i=1; i<n; i++){
        scanf(" %c", &nextCity);
        if(nextCity!=actualCity){
            if(nextCity=='S') san2Seat++;
            else seat2San++;
            actualCity=nextCity;
        }
    }
    printf(seat2San>san2Seat ? "YES":"NO");
    return 0;
}
