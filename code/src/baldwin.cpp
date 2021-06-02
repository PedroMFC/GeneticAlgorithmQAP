#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include "../include/includes.h"
using namespace std;
using namespace std::chrono; 

int **m_distancias;
int **m_flujo;
int size;

void greedyBald(vector<Cromosoma> &poblacion, int iteracion){
    int cambio_max = 10;

    if(iteracion > 100){
        cambio_max = 1;
    }

    for(int i=0; i<poblacion.size(); ++i){
        int cambio;

        Cromosoma S = poblacion[i];
        cambio = 0;

        for(int k=0; k<size && cambio < cambio_max; ++k){
            for(int j=k+1; j<size && cambio < cambio_max; ++j){
                int fT = fitness(S.permutacion, S.fitness, k, j);

                if(fT < S.fitness){
                    Cromosoma T = mutacionNoModifica(S, k, j);
                    S.permutacion = T.permutacion;
                    S.fitness = fT;
                    ++cambio;
                }

            }
        }

        poblacion[i].fitness = S.fitness; //Solo actualizamos el fitness
    }
}

int main (){
    srand (time(NULL));
    int tamanio_pob = 20;
    int generaciones = 500;
    int mostrar = 10;
    // Nombre del archivo
    time_t timetoday;
    time (&timetoday);
    string time = asctime(localtime(&timetoday));
    string nombre = "Blipa60a";

    string archivo = "./datos/lipa60a.dat";
    loadMatrixes(archivo);

    //Archivo de para almacenar los fitness que vamos obteniendo
    ofstream log("./results/Fitness-" +  nombre); //Lo usamos para alamcenar los resultados

    // Comenzamos

    auto start = high_resolution_clock::now(); 
    vector<Cromosoma> poblacion(tamanio_pob);
    vector<Cromosoma> pob_aux; // Para evaluar
    

    poblacion_inicial(poblacion); //Generamos poblacion inicial y evaluamos

    
    vector<Cromosoma> hijos;
    vector<Cromosoma> seleccionados;

    vector<Cromosoma> history;
    history.push_back(mejor(poblacion).first);

    greedyBald(poblacion, 0); //Evaluamos la población inicial
    for(int i=0; i<generaciones; ++i){
        seleccionReemplazamiento(poblacion, 2, 12, seleccionados);
        cruzar(seleccionados, tamanio_pob, hijos);
        mutar_hijos(hijos);
        greedyBald(hijos, i); // Evaluamos los hijos

        poblacion = reemplazoElitismo(poblacion, hijos, tamanio_pob);

        // Almacenar y mostrar resultados. Usamos los valores reales mediante una población auxiliar
        Cromosoma mej = mejor(poblacion).first;

        history.push_back(mej);
        log << mej.fitness << endl;

        if( i%mostrar == 0){
            cout << "Mejor Fitness "<< i << ": " << mej.fitness << endl;
        }

        //Limpiamos
        seleccionados.clear();
        hijos.clear();
        pob_aux.clear();
    }

    // Almacenamos la mejor permutación
    ofstream log2("./results/Permutacion-" + nombre); //Lo usamos para alamcenar los resultados
    Cromosoma mej = mejor(poblacion).first;
    for(int i=0; i<mej.permutacion.size();++i){
        log2 << mej.permutacion[i] << " ";
    }

    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    log << "Segundos empleados: " << (duration.count()/1000000.0) << endl;
}