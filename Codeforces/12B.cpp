#include <iostream>
#include <math.h>

using namespace std;

int a=0, b=0, i, j;
int c;
int arr[1000];
int totNums;
int numNoZero;
long potBase = 1, potFinal;
int indArr;
int lengthA, lengthB;
bool correcto;

int main()
{
    string sA, sB;
    cin >> sA >> sB;
    lengthA = sA.length();
    lengthB = sB.length();
    float tempA, tempB;
    for(i=0; i<sA.length(); i++){
        tempA = ((int)sA[i]-48)*pow(10, sA.length()-i-1);
        a+=tempA;
    }
    for(i=0; i<sB.length(); i++){
        tempB = ((int)sB[i]-48)*pow(10, sB.length()-i-1);
        b+=tempB;
    }
    ///casos para a=1 y a=0
    if(a==0){
        if(b==0 && lengthA == lengthB)
            correcto = true;
    }
    if(a==1){
        if(b==1 && lengthA == lengthB)
            correcto = true;
    }
    while(potBase<a){
            totNums++;
            potBase*=10;
    }
    ///reduce en uno porque si no se tiene una potencia de más
    potBase/=10;
    potFinal=potBase;
    ///acomoda en un arreglo por como queden
    while(a>0){
        arr[indArr]=a/potBase;
        if(a/potBase!=0)
            numNoZero++;
        a-=arr[indArr++]*potBase;
        potBase/=10;
    }
    ///ordena de menor a mayor
    int temp;
    for(i=0; i<totNums; i++){
        for(j=0; j<totNums-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    ///busca el menor número
    int minNum=10;
    int pivMin = -1;
    for(i=totNums-1; i>=0; i--){
        if(arr[i]<=minNum && arr[i]!=0){
            minNum=arr[i];
            pivMin = i;
        }
    }
    ///añade todos los ceros después del primer mínimo número que no sea cero
    int zeros = totNums-numNoZero;
    c+=minNum*potFinal;
    potFinal/=10;
    while(zeros>0){
        potFinal/=10;
        zeros--;
    }
    ///como estan ordenados añade los sig numeros bajando de centenas->decenas->unidades...
    for(i=pivMin+1; i<totNums; i++){
        c+=arr[i]*potFinal;
        potFinal/=10;
    }
    if(b==c && lengthA == lengthB)
        correcto = true;
    if(b==c && lengthA == lengthB)
        correcto = true;
    cout << (correcto? "OK" : "WRONG_ANSWER");
    return 0;
}
