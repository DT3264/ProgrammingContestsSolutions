#include<bits/stdc++.h>
using namespace std;
int main(){
    int pages, i;
    int days[7];
    cin >> pages;
    for(i=0; i<7; i++){
        cin >> days[i];
    }
    int pos=0;
    while(pages>0){
        pages-=days[pos++];
        pos%=7;
    }
    cout << (pos>0 ? pos : 7) << endl;
return 0;
}
