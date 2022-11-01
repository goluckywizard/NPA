#include <stdio.h>
#include <stdlib.h>
#include "NPA.h"
#include <string.h>
int main(int argc, char *argv[])
{
    //FILE *inpf;
    char P[11];

    int n;
    if (argc > 2)
    {
        if (NULL == strncpy(P, argv[1], 10))
            exit(1);
        n = atoi(argv[2]);
    }
    else
    {
        if (1 != scanf("%10s", P))
            return 1;
        if (1 != scanf("%10d", &n))
            return 2;
        //scanf("%s", P);
        //scanf("%d", &n);
    }
    unsigned int count_digit[10] = {0};
    int i = 0;
    while (P[i] != 0)
    {
        if (P[i] < '0' || P[i] > '9')
        {
            printf ("bad input");
            return 0;
        }
        count_digit[(int)(P[i++] - '0')]++;

    }
    i = 0;
    for (i = 0; i < 10; ++i)
    {
        if (count_digit[i] > 1)
        {
            printf ("bad input");
            return 0;
        }

    }
    npa(P, n);
    return 0;
}
