#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *a, int n)
{
    int i, j;
    int temp;
    for(i = 0; i < n; i++)
    {
        temp = *(a+i);
        for(j = i-1; j >= 0 && temp < *(a+j); j--)
        {
            *(a+j+1) = *(a+j);
        }
        *(a+j+1) = temp;
    }
    return;
}

void selection_sort(int *a, int n)
{
    int i, j;
    int min;
    int temp;
    for(i = 0; i < n; i++)
    {
        min = i;
        for(j = i+1; j < n ; j++)
        {
            if(*(a+j) < *(a+min))
                min = j;
        }
        temp = *(a+i);
        *(a+i) = *(a+min);
        *(a+min) = temp;
    }
    return;
}

void bubble_sort(int *a, int n)
{
    int i, j;
    int temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-1; j++)
        {
            if(*(a+j) > *(a+j+1))
            {
                temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }
    return;
}

int main()
{
    int n;
    int i;
    clock_t start, end;
    double diff;
    srand(time(NULL));

    printf("Please enter the number (<100000):  ");
    scanf("%d", &n);

    start = clock();

    int a[n];
    printf("BEFORE: ");
    for(i = 0; i < n; i++)
    {
        a[i] = rand();
        printf("%d, ", a[i]);
    }
    //¤T¿ï¤@
    insertion_sort(a, n);
    //selection_sort(a, n);
    //bubble_sort(a, n);
    printf("\nAFTER : ");
    for(i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }

    end = clock();
    diff = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\n--> %f sec", diff);

    return 0;
}
