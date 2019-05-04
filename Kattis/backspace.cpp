#include<stdio.h>
#include<vector>
using namespace std;
char str[(int)(1e6)+1];
vector<char> vec;
int main() {
    int i;
    scanf("%s", str);
    for(i=0; str[i]; i++){
        if(str[i]!='<'){
            vec.push_back(str[i]);
        }
        else{
            vec.pop_back();
        }
    }
    for(i=0; i<vec.size(); i++){
        printf("%c", vec[i]);
    }
    return 0;
}
