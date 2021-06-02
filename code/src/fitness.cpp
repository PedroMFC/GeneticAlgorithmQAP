#include <vector>
#include <iostream>
#include"../include/includes.h"
using namespace std;

/*
    Obtener el fitness o recalcularlo. En este último caso la permutación NO se ha modificado todavía,
    sigue siendo la original
*/
int fitness(const vector<int> &permutacion, int coste_ant, int i_ant, int j_ant){
    if( permutacion.size() == size){
        int coste = 0;

        if(coste_ant == -1){ // Lo calculamos por primera vez
            for(int i=0; i<size; ++i){
                for(int j=0; j<size; ++j){
                    coste += m_flujo[i][j]*m_distancias[permutacion[i]][permutacion[j]];
                }
            }
        } else{ // Lo recalculamos. Permutación NO lleva el cambio
            int diff1 = 0;
            int diff2 = 0;
            coste = coste_ant;
            for (int i=0; i<size; ++i){
                if(i != i_ant && i != j_ant){
                    int val = permutacion[i];
                    diff1 = m_distancias[val][permutacion[j_ant]] - m_distancias[val][permutacion[i_ant]];
                    diff2 = m_distancias[permutacion[j_ant]][val] - m_distancias[permutacion[i_ant]][val];
                    
                    coste += (m_flujo[i][i_ant] - m_flujo[i][j_ant])*diff1 + (m_flujo[i_ant][i] - m_flujo[j_ant][i])*diff2;
               }
            }
        }

        return coste;
    }

    return -1;
}

/*
Actualizar el fitness real de todos los individuos de la población
*/
void evaluar(vector<Cromosoma> &poblacion){
    for(int i=0; i<poblacion.size(); ++i){
        poblacion[i].fitness = fitness(poblacion[i].permutacion);
    }
}