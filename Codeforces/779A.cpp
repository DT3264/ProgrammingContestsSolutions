#include<stdio.h>
int arr1[6];
int arr2[6];
int main(){
    int n, i, t;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        arr1[t]++;
    }
    for(i=0; i<n; i++){
        scanf("%d", &t);
        arr2[t]++;
    }
    int contMov=0;
    for(i=0; i<6; i++){
        ///printf("start with %d %d at %d\n", arr1[i], arr2[i], i);
        while(arr1[i]>arr2[i]) arr1[i]--, arr2[i]++, contMov++;
        while(arr2[i]>arr1[i]) arr2[i]--, arr1[i]++, contMov++;
        ///printf("end with %d %d\n", arr1[i], arr2[i]);
    }
    bool cant = false;
    for(i=0; i<6; i++){
        if(arr1[i]!=arr2[i]) cant=true;
    }
    if(!cant){
        printf("%d", contMov/2);
    }
    else printf("-1");
    return 0;
}

