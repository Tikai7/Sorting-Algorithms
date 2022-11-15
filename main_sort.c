#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bulles.h"
#include "insertion.h"
#include "quick.h"
#include "heap.h"
#include "fusion.h"

void show_tab(long tab[], long taille)
{
    for (long i = 0; i < taille; i++)
        printf("tab[%d] = %d \n", i, tab[i]);
}

void fill_randomly(long tab[], long taille)
{
    srand(17);
    for (long i = 0; i < taille; i++)
        tab[i] = rand() % taille;
    printf("End of filling random \n");
}

void fill_sorted(long tab[], long taille)
{
    for (long i = 0; i < taille; i++)
        tab[i] = i;
    printf("End of filling sorted \n");
}

void fill_sorted_reverse(long tab[], long taille)
{
    for (long i = 0; i < taille; i++)
        tab[i] = taille - i;
    printf("End of filling sorted reverse \n");
}

void write_in_file(char *filename, long size, double duration, char *type)
{
    printf("Writing in %s type :%s \n", filename, type);
    FILE *fichier = fopen(filename, "a");
    fprintf(fichier, "-- Configuration : %s --\nSize : %d\nDuration %lf\n\n --------------------------------------------\n", type, size, duration);
    fclose(fichier);
}

int main()
{

    long TAILLES[] = {
        1 * pow(10.0, 5.0),
        2 * pow(10.0, 5.0),
        4 * pow(10.0, 5.0),
        8 * pow(10.0, 5.0),
        3.2 * pow(10.0, 6.0),
        // 6.4 * pow(10.0, 6.0),
        // 12.8 * pow(10.0, 6.0),
        // 25.6 * pow(10.0, 6.0),
        // 51.2 * pow(10.0, 6.0),
        1.024 * pow(10.0, 6.0),
        2.048 * pow(10.0, 6.0),
    };

    long size_tab = sizeof(TAILLES) / sizeof(TAILLES[0]);
    char file_name[] = "tri_insertion_2.txt";

    clock_t begin, end;

    for (long i = 0; i < size_tab; i++)
    {
        printf("%d \n", TAILLES[i]);
        long double duration;
        long *tab = (long *)malloc(sizeof(long) * TAILLES[i]);
        long tab_middle = TAILLES[i] % 2 ? TAILLES[i] / 2 : (TAILLES[i] / 2) + 1;
        // ------------------- RANDOM VALUES -------------------- //

        // fill_randomly(tab, TAILLES[i]);
        // begin = clock();
        // // triBulle(tab, TAILLES[i]);
        // // triInsertion(tab, TAILLES[i]);
        // // triFusion(tab, 0, TAILLES[i]);
        // triRapid(tab, 0, TAILLES[i]);
        // // triTas(tab, TAILLES[i], tab_middle);
        // end = clock();

        // // show_tab(tab,TAILLES[i]);
        // duration = ((long double)end - begin) / CLOCKS_PER_SEC;
        // printf("End of sorting random\n");

        // write_in_file(file_name, TAILLES[i], duration, "Randomly filled");

        // ------------------- SORTED VALUES -------------------- //

        fill_sorted(tab, TAILLES[i]);
        begin = clock();
        // triBulle(tab, TAILLES[i]);
        triInsertion(tab, TAILLES[i]);
        // triFusion(tab, 0, TAILLES[i]);
        // triRapid(tab, 0, TAILLES[i]);
        // triTas(tab, TAILLES[i], tab_middle);
        end = clock();

        // show_tab(tab,TAILLES[i]);
        duration = ((long double)end - begin) / CLOCKS_PER_SEC;
        printf("End of sorting sorted\n");
        write_in_file(file_name, TAILLES[i], duration, "Sorted");
        // ------------------- REVERSE SORTED VALUES -------------------- //

        // fill_sorted_reverse(tab, TAILLES[i]);
        // begin = clock();
        // // triBulle(tab, TAILLES[i]);
        // // triInsertion(tab, TAILLES[i]);
        // // triFusion(tab, 0, TAILLES[i]);
        // triRapid(tab, 0, TAILLES[i]);
        // // triTas(tab, TAILLES[i], tab_middle);
        // end = clock();

        // duration = ((long double)end - begin) / CLOCKS_PER_SEC;
        // printf("End of sorting reverse\n");
        // write_in_file(file_name, TAILLES[i], duration, "Reverse sorted");

        free(tab);
    }

    return 0;
}