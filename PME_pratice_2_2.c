#include <stdio.h>
#include <stdlib.h>

double number(char *str, char *concept, char *unit)
{
    char *str_num, *str_unit;
    str_num = strstr(str, concept);

    if(str_num != NULL)
    {
        str_unit = strstr(str_num, unit);
        if(*(str_unit-1) == 'm')
            return 0.001*atof(str_num+2);
        else if(*(str_unit-1) == 'k')
            return 1000*atof(str_num+2);
        else if(*(str_unit-1) == 'M')
            return 1000000*atof(str_num+2);
        else
            return atof(str_num+2);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    char str[100];
    double P, U, I;

    int i;
    char temp;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Problem #%d\n", i+1);

        if(i == 0)
            gets(&temp);

        gets(str);
        P = number(str, "P=", "W");
        U = number(str, "U=", "V");
        I = number(str, "I=", "A");
        if(P == 0)
            printf("P=%.2fW\n\n", U*I);
        else if(U == 0)
            printf("U=%.2fV\n\n", P/I);
        else
            printf("I=%.2fA\n\n", P/U);
    }

    return 0;
}
