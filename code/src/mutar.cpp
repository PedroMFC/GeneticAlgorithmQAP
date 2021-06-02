#include "../include/includes.h"
#include <vector>

void mutacion(Cromosoma &crom, int i, int j){
    int tmp= crom.permutacion[i];
    crom.permutacion[i] = crom.permutacion[j];
    crom.permutacion[j] = tmp;
}

Cromosoma mutacionNoModifica(const Cromosoma crom, int i, int j){
    Cromosoma mutado = crom;
    mutado.permutacion[i] = crom.permutacion[j];
    mutado.permutacion[j] = crom.permutacion[i];

    return mutado;
}

void mutar_hijos(vector<Cromosoma> &hijos){
    srand(time(NULL));
    int tam_hijos = hijos.size();

    
    for(int index = 0; index<tam_hijos; ){
        int i = rand() % size;
        int j = rand() % size;

            
        if(i != j){
            mutacion(hijos[index], i, j);
            hijos[index].fitness = fitness(hijos[index].permutacion);
            ++index;
        }

    }
}