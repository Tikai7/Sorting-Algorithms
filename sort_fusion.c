#include <stdio.h>
#include <stdlib.h>

int *fill_left_tab(int tab[], int taille)
{
    int *left_tab = (int *)malloc(sizeof(int) * taille);

    for (int i = 0; i < taille; i++)
        left_tab[i] = tab[i];

    return left_tab;
}

int *fill_right_tab(int tab[], int taille)
{
    int *right_tab = (int *)malloc(sizeof(int) * taille);

    int j = taille;
    for (int i = 0; i < taille; i++)
    {
        right_tab[i] = tab[j];
        j++;
    }

    return right_tab;
}

int *concatenate(int tab_A[], int tab_B[], int taille_A, int taille_B)
{
    if (taille_A <= 0)
        return tab_B;
    else if (taille_B <= 0)
        return tab_A;
    else if (tab_A[0] < tab_B[0])
    {
        int *newTab = (int *)malloc(sizeof(int) * (taille_A - 1));
        for (int i = 1; i < taille_A; i++)
            newTab[i - 1] = tab_A[i];

        int *preTab = concatenate(newTab, tab_B, taille_A - 1, taille_B);

        int taille_pre_tab = (int)(sizeof(preTab) / sizeof(preTab[0]));
        int *tab_to_return = (int *)malloc(sizeof(int) * taille_pre_tab + 1);

        tab_to_return[0] = tab_A[0];
        for (int i = 1; i < taille_pre_tab; i++)
            tab_to_return[i] = preTab[i - 1];

        return tab_to_return;
    }
    else
    {
        int *newTab = (int *)malloc(sizeof(int) * (taille_B - 1));
        for (int i = 1; i < taille_B; i++)
            newTab[i - 1] = tab_B[i];

        int *preTab = concatenate(newTab, tab_B, taille_A, taille_B - 1);

        int taille_pre_tab = (int)(sizeof(preTab) / sizeof(preTab[0]));
        int *tab_to_return = (int *)malloc(sizeof(int) * taille_pre_tab + 1);

        tab_to_return[0] = tab_B[0];
        for (int i = 1; i < taille_pre_tab; i++)
            tab_to_return[i] = preTab[i - 1];

        return tab_to_return;
    }
}

int *tri_fusion(int tab_T[], int taille_T)
{
    if (taille_T <= 1)
        return tab_T;
    else
    {
        int taille_left = taille_T % 2 == 0 ? taille_T / 2 : taille_T / 2 + 1;
        int taille_right = taille_T - taille_left;

        int *left_tab = fill_left_tab(tab_T, taille_left);
        int *right_tab = fill_right_tab(tab_T, taille_right);

        return concatenate(tri_fusion(left_tab, taille_left), tri_fusion(left_tab, taille_right), taille_left, taille_right);
    }
}

int main()
{
    int tab[4] = {1, 4, 3, 2};
    int *resultat = tri_fusion(tab, 4);

    for (int i = 0; i < 4; i++)
        printf("tab[%d] = %d \n", i, resultat[i]);
    return 0;
}