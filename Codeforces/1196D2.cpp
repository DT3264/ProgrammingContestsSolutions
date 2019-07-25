#include <stdio.h>
#include <algorithm>
#define ll long long
int r[200002];
int g[200002];
int b[200002];
char str[200002];
int main(){
    int q, i;
    scanf("%d", &q);
    char rgb[3]={'R', 'G', 'B'};
    int cR, cG, cB;
    while(q--){
        int n, k;
        cR=0;
        cG=0;
        cB=0;
        int rgbPos=0;
        scanf("%d%d", &n, &k);
        r[0]=0;
        g[0]=0;
        b[0]=0;
        for(i=0; i<n; i++){
            scanf(" %c", &str[i]);
            r[i+1]=0;
            g[i+1]=0;
            b[i+1]=0;
        }
        for(i=0; i<n; i++){
            if(str[i]!=rgb[rgbPos%3]){
                cR++;
            }
            if(str[i]!=rgb[(rgbPos+1)%3]){
                cG++;
            }
            if(str[i]!=rgb[(rgbPos+2)%3]){
                cB++;
            }
            rgbPos++;
            r[i+1]=cR;
            g[i+1]=cG;
            b[i+1]=cB;
        }
        int left=1, right=k;
        int ans=100000000;
        while(right<=n){
            ans=std::min(ans, r[right]-r[left-1]);
            ans=std::min(ans, g[right]-g[left-1]);
            ans=std::min(ans, b[right]-b[left-1]);
            left++;
            right++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
