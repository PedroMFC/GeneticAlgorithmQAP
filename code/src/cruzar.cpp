#include "../include/includes.h"
#include <iostream>
#include <algorithm>    // std::find
#include <stdlib.h>     /* srand, rand */
using namespace std;


// Auxiliar para comprobar durante las pruebas que sigue siendo una permutación válida
bool noBienCruzado(Cromosoma crom){
    int sumaBuena = (size-1)*(size/2);
    
    int suma = 0;
    for(int i=0; i<crom.permutacion.size(); ++i){
        suma += crom.permutacion[i];
    }

    if (suma != sumaBuena){
        cout << "Difieren " << sumaBuena  << " " << suma << endl;
        exit(-1);
    }
}


/*
    A partir de dos padres y el punto de cruce (en porcentaje) nos devuelve dos hijos
    formados de cruzar los anteriores
*/
vector<Cromosoma> crucePadres(Cromosoma p1, Cromosoma p2, float k_pctge = 0.5){
    vector<Cromosoma> hijos;
    hijos.resize(2);
    int k = static_cast<int>(k_pctge*size);

    Cromosoma h1, h2;
    h1.permutacion = p1.permutacion;
    h2.permutacion = p2.permutacion;

    int index_1 = k;
    int index_2 = k;
    vector<int>::iterator it1, last1;
    vector<int>::iterator it2, last2;
    last1 = h1.permutacion.begin()+k;
    last2 = h2.permutacion.begin()+k;

    for(int i=k; i<size; ++i){
        //Vemos si podemos rellenar el hijo 1
        it1 = find(h1.permutacion.begin(), last1, p2.permutacion[i]);

        if(it1 == last1){ //Si no lo ha encontrado
            h1.permutacion[index_1] = p2.permutacion[i];
            ++last1;
            ++index_1;
        } 

        //Vemos si podemos rellenar el hijo 2
        it2 = find(h2.permutacion.begin(), last2, p1.permutacion[i]);

        if(it2 == last2){ //Si no lo ha encontrado
            h2.permutacion[index_2] = p1.permutacion[i];
            ++last2;
            ++index_2;
        }


    }

    //Volvemos a rellenar el hijo 1 empezando desde el principio del padre
    int index_1_2 = 0;
    last1 = h1.permutacion.begin()+index_1;
    while(index_1 < size){
        it1 = find(h1.permutacion.begin(), last1, p2.permutacion[index_1_2]);

        if(it1 == last1){ //Si no lo ha encontrado
            h1.permutacion[index_1] = p2.permutacion[index_1_2];
            ++index_1;
        }

        ++index_1_2;
    }

    ///Volvemos a rellenar el hijo 2 empezando desde el principio del padre
    int index_2_2 = 0;
    last2 = h2.permutacion.begin()+index_2;
    while(index_2 < size){
        it2 = find(h2.permutacion.begin(), last2, p1.permutacion[index_2_2]);

        if(it2 == last2){ //Si no lo ha encontrado
            h2.permutacion[index_2] = p1.permutacion[index_2_2];
            ++index_2;
        }

        ++index_2_2;
    }
    
    noBienCruzado(h1);
    noBienCruzado(h2);

    hijos[0] = h1;
    hijos[1] = h2;


    return hijos;
}

/*
    Cruzamos la población de padres hasta obtener el número de hijos deseado
*/
void cruzar(vector<Cromosoma> seleccionados, int tamanio_pob_hijos,  vector<Cromosoma> &hijos){
    hijos.resize(tamanio_pob_hijos+1);
    int aniadidos = 0;

    int tam_seleccionados = seleccionados.size();
    while(aniadidos < tamanio_pob_hijos){
        int i = rand() % tam_seleccionados;
        int j = rand() % tam_seleccionados;

        if(i != j){
            vector<Cromosoma> hijos_aux = crucePadres(seleccionados[i], seleccionados[j]);

            hijos[aniadidos] = hijos_aux[0];
            hijos[aniadidos+1] = hijos_aux[1];

            aniadidos += 2;
        }
    }


    hijos.resize(tamanio_pob_hijos); //Por si nos pasamos al meter más hijos
}