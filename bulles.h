/* Tri à bulle */

#include <stdio.h>
void triBulle(long tab[], long taille);

void triBulle(long tab[], long taille)
{
  for (long i = 0; i < taille - 1; i++)
  {
    for (long j = 0; j < taille - i - 1; j++)
    {
      /* Pour un ordre décroissant on utilise < */
      if (tab[j] > tab[j + 1])
      {
        long tmp = tab[j];
        tab[j] = tab[j + 1];
        tab[j + 1] = tmp;
      }
    }
  }
}