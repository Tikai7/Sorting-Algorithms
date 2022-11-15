#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void triTas(long tab[], long tab_taille, long tab_middle);

void creer_tas(long tab[], long taille, long indice_racine)
{
    //---- Max_racine = indice_racine courante
    long max_racine = indice_racine;
    //--- Fils droits et gauche
    long fils_gauche = 2 * indice_racine + 1;
    long fils_droit = 2 * indice_racine + 2;

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
        long temp = tab[indice_racine];
        tab[indice_racine] = tab[max_racine];
        tab[max_racine] = temp;

        //--- la nouvel racine est l'indice du fils qu'on a inversé
        creer_tas(tab, taille, max_racine);
    }
}

void triTas(long tab[], long tab_taille, long tab_middle)
{
    /*
        --- Créer un Tas initial avec :
        --- Tab = liste
        --- Tab_taille = taille_liste
        --- i = racine courante
    */

    for (long i = tab_middle - 1; i >= 0; i--)
        creer_tas(tab, tab_taille, i);

    /*
        --- Récrer un tas en faisant
        --- Inverser premier element (element + le plus) avec dernier
        --- Refaire le tas avec comme taille n-1 (on prend plus en compte le dernier)

    */

    for (long i = tab_taille - 1; i >= 0; i--)
    {
        long temp = tab[0];
        tab[0] = tab[i];
        tab[i] = temp;

        //----- racine courante = 0 car on refait depuis le sommets
        //----- i = taille_tableau car on prend plus en compte le dernier element
        creer_tas(tab, i, 0);
    }
}
