#ifndef PROCEDIMIENTOS_H_INCLUDED
#define PROCEDIMIENTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define NUM_GENES 30    //Número de genes
#define NUM_GENERACIONES 100    //Número de generaciones
#define NUM_CROMOSOMAS 50     //Número de cromosomas
#define PROB_MUTACION 0.05     //Probabilidad de mutación
#define TOUR_SELECTION 3 // Parametro de tournament selection

void inicializa_poblacion(int poblacion[][NUM_GENES]);
int ffitness (int v[][NUM_GENES], int cromosoma);
void seleccion (int poblacion [][NUM_GENES], int mating_pool[][NUM_GENES], int generacion);
void crossover(int mating_pool[][NUM_GENES]);
void mutacion (int mating_pool[][NUM_GENES]);
void supervivencia (int poblacion_o[][NUM_GENES], int poblacion_n[][NUM_GENES], int mejor[], int *mejorfit, int generacion, int *mejorgen);

#endif // PROCEDIMIENTOS_H_INCLUDED
