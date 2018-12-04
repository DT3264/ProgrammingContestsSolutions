#include<stdio.h>
struct segment{
    int ini=-1;
    int length=0;
    bool canMatchPrev=false;
};

segment segments[100000];
int segmentsCant=0;

int contGold=0;

int main(){
    int n, i;
    char str[100000];
    scanf("%d", &n);
    scanf("%s", str);
    bool lastWasSilver=true;
    for(i=0; i<n; i++){
        if(str[i]=='G'){
            contGold++;
            if(lastWasSilver){
                lastWasSilver=false;
                segments[segmentsCant].ini=i;
                if(segmentsCant>0){
                    if(str[i-2]=='G'){
                        segments[segmentsCant].canMatchPrev=true;
                    }
                }
            }
            segments[segmentsCant].length++;
        }
        else{
            lastWasSilver=true;
            segmentsCant++;
        }
    }
    if(str[n-1]=='G') segmentsCant++;
    int maxLen=0;
    ///Search the bigest subset of golds by itself
    for(i=0; i<segmentsCant; i++){
        int actualSegment = segments[i].length;
        ///Try pasting a gold to the side
        if(maxLen<actualSegment+1 && actualSegment+1 <=contGold){
            maxLen = actualSegment+1;
        }
        ///Try without pasting a gold
        if(maxLen<actualSegment){
            maxLen = actualSegment;
        }
    }
    ///Search the best join of two subsets
    for(i=1; i<segmentsCant; i++){
        if(segments[i].canMatchPrev){
            int actualSegment = segments[i].length + segments[i-1].length;
            ///If can paste another gold
            if(actualSegment+1 <= contGold && maxLen < actualSegment+1){
                maxLen = actualSegment+1;
            }
            ///If cannot replace a silver with other subset's gold
            if(actualSegment <= contGold && maxLen < actualSegment){
                maxLen = actualSegment;
            }
        }
    }
    printf("%d", maxLen);
    return 0;
}
