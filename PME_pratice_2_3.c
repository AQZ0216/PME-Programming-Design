#include <stdio.h>
#include <stdlib.h>

int scan(int *n)
{
    scanf("%d", n);
    return *n;
}

int calculate(int num)
{
    int a[10];
    int descend = 0;
    int assend = 0;
    int length;

    int temp;
    int i, j;

    for(i = 0; num != 0; i++)
    {
        *(a+i) = num%10;
        num = num/10;
    }
    length = i;

    for(i = 0; i < length; i++)
    {
        for(j = 0; j < length-1; j++)
        {
            if(*(a+j) > *(a+j+1))
            {
                temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }

    for(i = length-1; i >= 0; i--)
    {
        descend = 10*descend + *(a+i);
    }

    for(i = 0; i < length; i++)
    {
        assend = 10*assend + *(a+i);
    }

    printf("%d - %d = %d\n", descend, assend, descend-assend);
    return descend-assend;
}

int find(int *database, int length)
{
    int i;
    for(i = 0; i < length-1; i++)
    {
        if(*(database+i) == *(database+length-1))
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    int database[5000] = {0};
    int length;

    while(scan(&n) != 0)
    {
        printf("Original number was %d\n", n);

        length = 0;
        while(find(database, length) == 0)
        {
            n = calculate(n);
            database[length] = n;
            length++;
        }
        printf("Chain length %d\n\n", length);
    }

    return 0;
}
