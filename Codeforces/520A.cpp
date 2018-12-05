#include<stdio.h>
#include<string>
#include<string.h>
char str[100];
int arr[27];

int main (){
    int n;
    scanf("%d %s", &n, &str);
    for(int i=0; i<n; i++){
        arr[tolower(str[i])-'a']++;
    }
    bool hasAllLetters=true;
    for(int i=0; i<26 && hasAllLetters; i++){
        if(arr[i]==0) hasAllLetters=false;
    }
    printf(hasAllLetters ? "YES" : "NO");
    return 0;
}
