#include<stdio.h>
#include<string.h>

bool toRight;
char realChar(char aChar){
     if(aChar=='q') return toRight ? 'w' : 'p';
else if(aChar=='w') return toRight ? 'e' : 'q';
else if(aChar=='e') return toRight ? 'r' : 'w';
else if(aChar=='r') return toRight ? 't' : 'e';
else if(aChar=='t') return toRight ? 'y' : 'r';
else if(aChar=='y') return toRight ? 'u' : 't';
else if(aChar=='u') return toRight ? 'i' : 'y';
else if(aChar=='i') return toRight ? 'o' : 'u';
else if(aChar=='o') return toRight ? 'p' : 'i';
else if(aChar=='p') return toRight ? 'q' : 'o';

else if(aChar=='a') return toRight ? 's' : ';';
else if(aChar=='s') return toRight ? 'd' : 'a';
else if(aChar=='d') return toRight ? 'f' : 's';
else if(aChar=='f') return toRight ? 'g' : 'd';
else if(aChar=='g') return toRight ? 'h' : 'f';
else if(aChar=='h') return toRight ? 'j' : 'g';
else if(aChar=='j') return toRight ? 'k' : 'h';
else if(aChar=='k') return toRight ? 'l' : 'j';
else if(aChar=='l') return toRight ? ';' : 'k';
else if(aChar==';') return toRight ? 'a' : 'l';

else if(aChar=='z') return toRight ? 'x' : '/';
else if(aChar=='x') return toRight ? 'c' : 'z';
else if(aChar=='c') return toRight ? 'v' : 'x';
else if(aChar=='v') return toRight ? 'b' : 'c';
else if(aChar=='b') return toRight ? 'n' : 'v';
else if(aChar=='n') return toRight ? 'm' : 'b';
else if(aChar=='m') return toRight ? ',' : 'n';
else if(aChar==',') return toRight ? '.' : 'm';
else if(aChar=='.') return toRight ? '/' : ',';
else if(aChar=='/') return toRight ? 'z' : '.';
}

int main(){
    char dir, str[110];
    int i;
    scanf("%c %s", &dir, str);
    int strLen = strlen(str);
    if(dir=='L') toRight=true;
    for(i=0; i<strLen; i++){
        printf("%c", realChar(str[i]));
    }
    return 0;
}
