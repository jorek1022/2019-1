#include <stdio.h>
#include "InfixCalculator.c"

int main(void)
{
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";

    printf("%s = %d \n", exp1, EvalInfixExp(exp1));
    printf("%s = %d \n", exp1, EvalInfixExp(exp1));
    printf("%s = %d \n", exp1, EvalInfixExp(exp1));

    return 0;
}