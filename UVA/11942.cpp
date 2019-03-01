#include<stdio.h>
#include<algorithm>
int main(){
    int n, i;
    int arr[10];
    bool min2Max=true;
    bool max2Min=true;
    scanf("%d", &n);
    printf("Lumberjacks:\n");
    while(n--){
        min2Max=max2Min=true;
        for(i=0; i<10; i++){
            scanf("%d", &arr[i]);
        }
        for(i=1; i<10 && min2Max; i++){
            if(std::max(arr[i], arr[i-1])!=arr[i]){
                ///if the actual is lower
                ///(should be greather)
                min2Max=false;

            }
        }
        for(i=1; i<10 && max2Min; i++){
            if(std::min(arr[i],arr[i-1])!=arr[i]){
                ///if the actual is greather
                ///(should be lower)
                max2Min=false;
            }
        }
        printf("%s\n", (min2Max || max2Min ? "Ordered" : "Unordered"));
    }
    return 0;
}
