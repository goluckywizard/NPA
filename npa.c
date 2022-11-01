#include "NPA.h"
void swap (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void next_purmutation (char *P, int count)
{
    int is_all = 1;
    for (int i = 1; i < count; ++i)
    {
        if (P[i] > P[i - 1])
            is_all = 0;
    }
    if (is_all == 1)
    {
        exit(0);
    }

    int l = 1, j = 0;
    for (int i = 0; i < count - 1; ++i)
    {
        if (P[i] < P[i + 1])
            j = i;
    }
    for (int i = j + 1; i < count; ++i)
    {
        if (P[i] > P[j])
            l = i;
    }

    swap(&P[l], &P[j]);
    for (int i = j + 1; i < (count + (j + 1)) / 2; ++i)
    {
        swap(&P[i], &P[count - i + j]);
    }
    printf("%s\n", P);
}

void npa (char *P, int n)
{
    int count = 0;
    while (P[count] != 0)
    {
        count++;
    }
    for (int i = 0; i < n; ++i)
    {
        next_purmutation(P, count);
    }
}
