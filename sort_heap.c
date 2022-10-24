#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

void tri_swap(int tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        for (int j = i; j < taille; j++)
        {
            if (tab[i] < tab[j])
            {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

void afficher_tab(int tab[], int taille)
{
    for (int i = 0; i < taille; i++)
        printf("%d ", tab[i]);
}

int main()
{
    srand(17);
    //-------------------------------- Variables
    clock_t start, end;

    FILE *fichier = NULL;
    double cpu_time_used;

    int TAILLES[13] = {
        5 * pow(10.0, 4.0),
        1 * pow(10.0, 5.0),
        2 * pow(10.0, 5.0),
        4 * pow(10.0, 5.0),
        8 * pow(10.0, 5.0),
        3.2 * pow(10.0, 6.0),
        6.4 * pow(10.0, 6.0),
        12.8 * pow(10.0, 6.0),
        25.6 * pow(10.0, 6.0),
        51.2 * pow(10.0, 6.0),
        1024 * pow(10.0, 6.0),
        2048 * pow(10.0, 6.0),
    };

    //------------------------------------------------------- POUR TOUTE LES TAILLES
    for (int i = 0; i < 13; i++)
    {

        //---------------------------------------------------- On crée un tableau de taille TAILLE[i]
        int *tab = (int *)malloc(sizeof(int) * TAILLES[i]);
        int size_tab = TAILLES[i];
        int size_middle = (int)(TAILLES[i] / 2);

        //---------------------------------------------------- REMPLISSAGE

        for (int j = 0; j < TAILLES[i]; j++)
            tab[j] = rand() % TAILLES[i];
        //---------------------------------------------------- RANDOM VALUE
        start = clock();
        tri_tas(tab, size_tab, size_middle);
        end = clock();
        cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;

        fichier = fopen("resultat_heap_random.txt", "a");
        if (fichier)
        {
            fprintf(fichier, "Random values : %d  \n", cpu_time_used);
            fclose(fichier);
        }
        //---------------------------------------------------- SORTED VALUE

        tri_tas(tab, size_tab, size_middle);

        start = clock();
        tri_tas(tab, size_tab, size_middle);
        end = clock();
        cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;

        fichier = fopen("resultat_heap_sorted.txt", "a");
        if (fichier)
        {
            fprintf(fichier, "Sorted values : %d  \n", cpu_time_used);
            fclose(fichier);
        }

        //---------------------------------------------------- SORTED VALUE (inverse)

        tri_swap(tab, size_tab);

        start = clock();
        tri_tas(tab, size_tab, size_middle);
        end = clock();
        cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;

        fichier = fopen("resultat_heap_sorted_inverse.txt", "a");
        if (fichier)
        {
            fprintf(fichier, "Sorted Inverse values : %d  \n", cpu_time_used);
            fclose(fichier);
        }
    }

    return 0;
}