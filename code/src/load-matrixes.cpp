#include <string>
#include <iostream>
#include <fstream>
#include"../include/includes.h"
using namespace std;

void loadMatrixes(string file){
    ifstream fmatrices;

    fmatrices.open(file, ios::in);

    fmatrices >> size; 

    // Matriz de flujo
    m_flujo = new int*[size];
    for(int i =0; i<size; ++i){
        m_flujo[i] = new int[size];
        for(int j=0; j<size; ++j){
            fmatrices >> m_flujo[i][j];
        }
    }

    // Matriz de distancias
    m_distancias = new int*[size];
    for(int i =0; i<size; ++i){
        m_distancias[i] = new int[size];
        for(int j=0; j<size; ++j){
            fmatrices >> m_distancias[i][j];
        }
    }
}