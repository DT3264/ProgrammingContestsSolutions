#include<stdio.h>
char arr[2010][2010];
bool alreadyTookSeat[2010][2010];

int n, m, c, i, j, x, y;
long long actualPlaces=0, posiblePlaces=0;
int main (){
    scanf("%d %d %d", &n, &m, &c);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    ///Normal algorithm
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(arr[i][j]=='.'){
                actualPlaces++;
            }
            else{
                actualPlaces=0;
            }
            if(actualPlaces>=c) posiblePlaces++;
        }
        actualPlaces=0;
    }
    actualPlaces=0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(arr[j][i]=='.') actualPlaces++;
            else actualPlaces=0;
            if(actualPlaces>=c) posiblePlaces++;
        }
        actualPlaces=0;
    }
    ///Hack for the case c==1
    if(c==1) printf("%lld", posiblePlaces/2);
    else printf("%lld", posiblePlaces);
    return 0;
}
