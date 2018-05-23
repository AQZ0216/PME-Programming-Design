#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scan(int *n)
{
    scanf("%d", n);
    return *n;
}

int transform(char *text, char *rule, char *replace)
{
    char copy[255];
    char *position = strstr(text, rule);
    int len_text;
    int len_position;
    int len_rule = strlen(rule);
    while(position != NULL)
    {
        len_text = strlen(text);
        len_position = strlen(position);
        strcpy(copy, text);
        *(text + len_text-len_position) = '\0';
        strcat(text, replace);
        strcat(text, copy + len_text-len_position+len_rule);
        position = strstr(text, rule);
    }
    return;
}

int main()
{
    int n;
    char temp;
    char rule[10][80];
    char replace[10][80];
    char text[255];

    int i;

    while(scan(&n) != 0)
    {
        gets(&temp);
        for(i = 0; i < n; i++)
        {
            gets(rule[i]);
            gets(replace[i]);
        }
        gets(text);
        for(i = 0; i < n; i++)
        {
            transform(text, rule[i], replace[i]);
        }
        puts(text);
    }

    return 0;
}
