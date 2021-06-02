#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <execution>
#include "../include/includes.h"
using namespace std;
using namespace std::chrono; 

int **m_distancias;
int **m_flujo;
int size;



void greedyLam(vector<Cromosoma> &poblacion){
    int max_cambio = 5; //Cambiar a partir de una iteración

    for(int i=0; i<poblacion.size(); ++i){
        int cambio;
        //do{
            Cromosoma S = poblacion[i];
            cambio = 0;

            for(int k=0; k<size && cambio < max_cambio; ++k){
                for(int j=k+1; j<size && cambio < max_cambio; ++j){
                    int fT = fitness(S.permutacion, S.fitness, k, j);

                    Cromosoma T = mutacionNoModifica(S, k, j);
                    int fTBueno = fitness(T.permutacion);

                    cout << "ft " << fT << " / Bueno " << fTBueno << endl; 

                    if(fT < S.fitness){
                        //cout << "Mejorado de " << S.fitness << " a " << fT << endl;
                        Cromosoma T = mutacionNoModifica(S, k, j);
                        S.permutacion = T.permutacion;
                        S.fitness = fT;
                        ++cambio;
                    }

                }
            }

            poblacion[i] = S;   //Actualizamos la permutacion y el fitness

        //} while(cambio);

        //cout << "Acabado con " << i << endl;
    }
}

int main (){
    srand (time(NULL));
    int tamanio_pob = 5;
    int generaciones = 100;
    int mostrar = 1;

    string archivo = "./datos/tai256c.dat";
    loadMatrixes(archivo);

    //Archivo de para almacenar los fitness que vamos obteniendo
    time_t timetoday;
    time (&timetoday);
    string time = asctime(localtime(&timetoday));

    ofstream log("./results/Lamarck-Fitness-" + time); //Lo usamos para almacenar los resultados

    // Comenzamos

    auto start = high_resolution_clock::now(); 
    vector<Cromosoma> poblacion(tamanio_pob);


    poblacion_inicial(poblacion); //Generamos poblacion inicial y evaluamos
    
    vector<Cromosoma> hijos;
    vector<Cromosoma> seleccionados;

    vector<Cromosoma> history;
    history.push_back(mejor(poblacion).first);

    greedyLam(poblacion);

/*
    for(int i=0; i<generaciones; ++i){
        greedyLam(poblacion);
        seleccion(poblacion, 2, 15, seleccionados);
        //seleccionExtremos(poblacion, 2, 15, seleccionados);
        cruzar(seleccionados, tamanio_pob, hijos);
        mutar_hijos(hijos);
        poblacion = reemplazoElitismo(poblacion, hijos, tamanio_pob);

        // Alamcenar y mostrar resultados

        Cromosoma mej = mejor(poblacion).first;

        history.push_back(mej);
        log << mej.fitness << endl;

        if(history[i].fitness < history[i+1].fitness){
            cout << "Algo va mal. Hemos pasado de " << history[i].fitness << " a " << history[i+1].fitness;
            exit(-1);
        }

        if( i%mostrar == 0){
            cout << "Mejor Fitness "<< i << ": " << mej.fitness << endl;
        }

        //Limpiamos
        seleccionados.clear();
        hijos.clear();
    }

    // Almacenamos la mejor permutación
    ofstream log2("./results/Lamarck-Permutacion-" + time); //Lo usamos para almacenar los resultados
    Cromosoma mej = mejor(poblacion).first;
    for(int i=0; i<mej.permutacion.size();++i){
        log2 << mej.permutacion[i] << " ";
    }

    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    log << "Segundos empleados: " << (duration.count()/1000000.0) << endl;*/
}