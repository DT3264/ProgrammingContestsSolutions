#include<stdio.h>
int n, bi, ba, ch, i, t;
int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        if(i%3==0) ch+=t;
        else if(i%3==1) bi+=t;
        else if(i%3==2) ba+=t;
    }
    if(ch>bi && ch>ba) printf("chest");
    else if(bi>ch && bi>ba) printf("biceps");
    else if(ba>bi && ba>ch) printf("back");
    return 0;
}



