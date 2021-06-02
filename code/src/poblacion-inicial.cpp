#include"../include/includes.h"
#include <algorithm>    // std::random_shuffle
using namespace std;


// random generator function:
int myrandom (int i) { return std::rand()%i;}

void poblacion_inicial(vector<Cromosoma> &poblacion){

    // Rellenamos primero con los números oredenados
    vector<int> aux(size,0);
    for(int i=0; i<size; ++i){
        aux[i] = i;
    }

    //Asignamos y "permutamos"
    for(int i=0; i<poblacion.size(); ++i){
        poblacion[i].permutacion = aux; 
        random_shuffle(poblacion[i].permutacion.begin(), poblacion[i].permutacion.end());
        poblacion[i].fitness = fitness(poblacion[i].permutacion);
    }

    
}