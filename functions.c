#include <stdio.h>


int identity(int a){
    return a;
}

int main()
{
    int var = 10;
    printf("%d = %d", var, identity(var));

    return 0;
}