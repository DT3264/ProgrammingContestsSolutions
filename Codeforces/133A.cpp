#include <stdio.h>
#include <string.h>

int main (){

    char c [300];
    int cont=0;
    int con=0;

    scanf("%s", c);

    for(int i = 0; i < strlen(c); i++){
        if(c[i] == 'H' || c[i] == 'Q' || c[i] == '9'){
            cont++;
        }
    }
    if (cont>0){
        printf("YES");
    } else{
        printf("NO");
    }

    return 0;
}
