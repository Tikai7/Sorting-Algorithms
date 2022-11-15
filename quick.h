#include <stdio.h>

void triRapid(long tab[], long first, long last);

void permuter(long *a, long *b)
{
    long tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void triRapid(long tab[], long first, long last)
{
    long pivot, i, j;
    if (first < last)
    {
        pivot = (first + last) / 2;
        i = first;
        j = last;
        while (i < j)
        {
            while (tab[i] <= tab[pivot] && i < last)
                i++;
            while (tab[j] > tab[pivot])
                j--;
            if (i < j)
            {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}
