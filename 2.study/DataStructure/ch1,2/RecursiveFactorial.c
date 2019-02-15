#include <stdio.h>

int Factorial(int num)
{
    if(num == 0)
        return 1;
    else
        return num * Factorial(num-1);
}

int main(void)
{
    int num = 10;
    int result = Factorial(num);

    printf("%d ! = %d \n", num, result);

    printf("%d : ",Factorial(5));

    return 0;
}