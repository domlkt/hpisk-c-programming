#include <stdio.h>

int main(){

    //Compilezeit vs Laufzeit!!
    
    int a = 100;
    int *ptrToA = &a;
    
    printf("Wert von a:\t\t\t%d\n", a);
    printf("Adresse von a:\t\t\t%p\n", ptrToA);
    printf("Adresse von Pointer zu a:\t%p\n", &ptrToA);

}