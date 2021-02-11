#include "procedimientos.h"

int main()
{
    int poblacion[NUM_CROMOSOMAS][NUM_GENES];
    int mating_pool[NUM_CROMOSOMAS][NUM_GENES];
    int i = 0, j, mejor_fit, mejor_gen = 0;
    int mejor[NUM_GENES];
    srand(time(NULL));

    inicializa_poblacion(poblacion);
    mejor_fit = ffitness(poblacion, 0);
    while (i < NUM_GENERACIONES)
    {
        seleccion(poblacion, mating_pool, i);
        crossover(mating_pool);
        mutacion(mating_pool);
        supervivencia(poblacion, mating_pool, mejor, &mejor_fit, i, &mejor_gen);

        if(mejor_fit == 0)
        {
            printf("\nLa contrasenya binaria es: ");
            for (j = 0; j < NUM_GENES; j++)
            {
                printf("%d", mejor[j]);
            }
            printf("\nLa generacio on ha sigut trobada es la %d\n", i);
            return 0;
        }
        i++;
    }
    printf("\nNo s'ha trobat una contrasenya correcta, pero la millor ha sigut: \n");

    for (j = 0; j < NUM_GENES; j++)
    {
        printf("%d", mejor[j]);
    }

    printf("\nLa generacio on ha sigut trobada es la %i, amb un fitness de %i\n", mejor_gen, mejor_fit);

    return 0;
}
