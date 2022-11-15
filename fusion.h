#include <stdio.h>
#include <stdlib.h>

void triFusion(long tab[], long debut, long fin);

void fusion(long tab[], long debut, long milieu, long fin)
{
    long taille_left = milieu - debut + 1;
    long taille_right = fin - milieu;

    long *left_tab = (long *)malloc(sizeof(long) * taille_left);
    long *right_tab = (long *)malloc(sizeof(long) * taille_right);

    for (long i = 0; i < taille_left; i++)
        left_tab[i] = tab[debut + i];

    for (long i = 0; i < taille_right; i++)
        right_tab[i] = tab[milieu + 1 + i];

    long compteur_left = 0;
    long compteur_right = 0;
    long compteur = debut;

    while (compteur_left < taille_left && compteur_right < taille_right)
    {
        if (left_tab[compteur_left] <= right_tab[compteur_right])
        {
            tab[compteur] = left_tab[compteur_left];
            compteur_left++;
        }
        else
        {
            tab[compteur] = right_tab[compteur_right];
            compteur_right++;
        }
        compteur++;
    }

    while (compteur_left < taille_left)
    {
        tab[compteur] = left_tab[compteur_left];
        compteur_left++;
        compteur++;
    }

    while (compteur_right < taille_right)
    {
        tab[compteur] = right_tab[compteur_right];
        compteur_right++;
        compteur++;
    }
    free(left_tab);
    free(right_tab);
}

void triFusion(long tab[], long debut, long fin)
{
    if (debut < fin)
    {
        long milieu = (debut + fin) / 2;
        triFusion(tab, debut, milieu);
        triFusion(tab, milieu + 1, fin);

        fusion(tab, debut, milieu, fin);
    }
}
