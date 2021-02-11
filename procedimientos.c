#include "procedimientos.h"

/**********************************************************
ComptaA
Funció que compta quantes vegades apareix la lletra ‘a’
en una cadena de caràcters. També contempla la majúscula i
les diferents opcions amb accent obert.
Paràmetres:
Cadena: cadena de caràcters a examinar
Retorn: la funció retorna un enter que indica el número
de lletres ‘a’ que s’han trobat.
**********************************************************/

void inicializa_poblacion(int poblacion[][NUM_GENES])
{
    int i, j;

    for (i = 0; i < NUM_CROMOSOMAS; i++)
    {
        for(j = 0; j < NUM_GENES; j++)
        {
            poblacion[i][j] = rand() % 2;
        }
    }
}

int ffitness(int poblacion[][NUM_GENES], int cromosoma)
{
    int fitness = 0, i;

    for (i = 1; i <= NUM_GENES; i++)
    {
        fitness = fitness + poblacion[cromosoma][i - 1]*i*i;
    }

    fitness = fitness - 1977;

    if (fitness < 0)
    {
        return -fitness;
    }
    else
    {
        return fitness;
    }
}

void seleccion(int poblacion[][NUM_GENES], int mating_pool[][NUM_GENES], int generacion)
{
    int fitness[NUM_CROMOSOMAS];
    int tour_selection[TOUR_SELECTION];
    int i, j, mejor_fit, mejor_cromo;

    fitness[0] = ffitness(poblacion, 0);
    mejor_fit = ffitness(poblacion, 0);
    mejor_cromo = 0;
    for (i = 1; i < NUM_CROMOSOMAS; i++)
    {
        fitness[i] = ffitness(poblacion, i);
        if (ffitness(poblacion, i) < mejor_fit)
        {
            mejor_fit = ffitness(poblacion, i);
            mejor_cromo = i;
        }
    }

    printf("El millor cromosoma de la generacio %d es ", generacion);
    for (j = 0; j < NUM_GENES; j++)
    {
        printf("%d", poblacion[mejor_cromo][j]);
    }
    printf("\nAmb un fitness de %d\n\n", mejor_fit);

    for (i = 0; i < NUM_CROMOSOMAS; i++)
    {
        for (j = 0; j < TOUR_SELECTION; j++)
        {
            tour_selection[j] = rand() % NUM_CROMOSOMAS;
        }
        mejor_cromo = tour_selection[0];

        for (j = 1; j < TOUR_SELECTION; j++)
        {
            if (fitness[tour_selection[j]] < fitness[mejor_cromo])
            {
                mejor_cromo = tour_selection[j];
            }
        }

        for (j = 0; j < NUM_GENES; j++)
        {
            mating_pool[i][j] = poblacion[mejor_cromo][j];
        }
    }
}

void crossover (int mating_pool[][NUM_GENES])
{
    int i, j, punt, aux;

    for (i = 0; i < NUM_CROMOSOMAS - 1; i = i + 2)
    {
        punt = rand() % NUM_GENES;
        for (j = punt; j < NUM_GENES; j++)
        {
            aux = mating_pool[i][j];
            mating_pool[i][j] = mating_pool[i + 1][j];
            mating_pool[i + 1][j] = aux;
        }
    }
}

void mutacion (int mating_pool[][NUM_GENES])
{
    int prob, i, j;

    for (i = 0; i < NUM_CROMOSOMAS; i++)
    {
        for (j = 0; j < NUM_GENES; j++)
        {
            prob = rand() % 101;

            if (prob <= (PROB_MUTACION * 100))
            {
                if (mating_pool[i][j] == 0)
                    mating_pool[i][j] = 1;
                else if (mating_pool[i][j] == 1)
                    mating_pool[i][j] = 0;
            }
        }
    }
}

void supervivencia (int poblacion_o[][NUM_GENES], int poblacion_n[][NUM_GENES], int mejor[], int *mejor_fit, int generacion, int *mejor_gen)
{
    int i, j, fit;

    for (i = 0; i < NUM_CROMOSOMAS; i++)
    {
        fit = ffitness(poblacion_o, i);

        if(fit < *mejor_fit)
        {
            *mejor_fit = fit;
            *mejor_gen = generacion;
            for(j = 0; j < NUM_GENES; j++)
            {
                mejor[j] = poblacion_o[i][j];
            }
        }

        for (j = 0; j < NUM_GENES; j++)
        {
            poblacion_o[i][j] = poblacion_n[i][j];
        }
    }
}
