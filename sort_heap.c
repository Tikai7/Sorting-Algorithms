#include <stdio.h>
#include <stdlib.h>

void creer_tas(int tab[], int taille, int indice_racine)
{
    //---- Max_racine = indice_racine courante
    int max_racine = indice_racine;
    //--- Fils droits et gauche
    int fils_gauche = 2 * indice_racine + 1;
    int fils_droit = 2 * indice_racine + 2;

    //--- On compare les valeurs et on swap si fils gauche ou droit + GRAND
    if (fils_gauche < taille && tab[fils_gauche] > tab[max_racine])
        max_racine = fils_gauche;

    if (fils_droit < taille && tab[fils_droit] > tab[max_racine])
        max_racine = fils_droit;

    /*
        --- Si l'element racien de base n'était pas le sommet,
        --- on inverse avec le fils et on cree un autre tas
    */
    if (max_racine != indice_racine)
    {
        int temp = tab[indice_racine];
        tab[indice_racine] = tab[max_racine];
        tab[max_racine] = temp;

        //--- la nouvel racine est l'indice du fils qu'on a inversé
        creer_tas(tab, taille, max_racine);
    }
}

void tri_tas(int tab[], int tab_taille, int tab_middle)
{
    /*
        --- Créer un Tas initial avec :
        --- Tab = liste
        --- Tab_taille = taille_liste
        --- i = racine courante
    */

    for (int i = tab_middle - 1; i >= 0; i--)
        creer_tas(tab, tab_taille, i);

    /*
        --- Récrer un tas en faisant
        --- Inverser premier element (element + le plus) avec dernier
        --- Refaire le tas avec comme taille n-1 (on prend plus en compte le dernier)

    */

    for (int i = tab_taille - 1; i >= 0; i--)
    {
        int temp = tab[0];
        tab[0] = tab[i];
        tab[i] = temp;

        //----- racine courante = 0 car on refait depuis le sommets
        //----- i = taille_tableau car on prend plus en compte le dernier element
        creer_tas(tab, i, 0);
    }
}

int main()
{
    int tab[4] = {1, 4, 3, 2};
    tri_tas(tab, 4, 2);

    for (int i = 0; i < 4; i++)
        printf("tab[%d] = %d \n", i, tab[i]);
    return 0;
}