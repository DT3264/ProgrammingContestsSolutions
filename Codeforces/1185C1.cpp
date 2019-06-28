#include <bits/stdc++.h>
using namespace std;
struct test{
    int test;
    int index;
};
bool compareTests(test t1, test t2){
    return t1.test<t2.test;
}
vector<test> tests, sortedTests;
int total;
void insertTest(test t){
    total+=t.test;
    tests.push_back(t);
    sortedTests.push_back(t);
    sort(sortedTests.begin(), sortedTests.end(), compareTests);
}
int getMinN(int ind, int &m){
    int actTotal=total;
    int res=0;
    for(int i=sortedTests.size()-1; i>=0 && actTotal>m; i--){
        if(sortedTests[i].index!=ind){
            actTotal-=sortedTests[i].test;
            res++;
        }
    }
    return res;
}
int main(){
    int n, m, i, t;
    scanf("%d%d", &n, &m);
    int arr[101];
    scanf("%d", &t);
    insertTest({t, 0});
    printf("0");
    int minN;
    for(i=1; i<n; i++){
        scanf("%d", &t);
        insertTest({t, i});
        minN=getMinN(i, m);
        printf(" %d", minN);
    }
    return 0;
}
