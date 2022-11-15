#include <stdio.h>
#include <stdlib.h>

void triInsertion(long tab[], long SIZE);
/* Tri par insertion */

void triInsertion(long tab[], long SIZE)
{
  long i, j, tmp;

  for (i = 1; i <= SIZE - 1; i++)
  {
    j = i;

    while (j > 0 && tab[j - 1] > tab[j])
    {
      tmp = tab[j];
      tab[j] = tab[j - 1];
      tab[j - 1] = tmp;

      j--;
    }
  }
}