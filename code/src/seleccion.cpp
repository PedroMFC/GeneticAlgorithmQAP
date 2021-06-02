#include "../include/includes.h"
#include <bits/stdc++.h>
using namespace std;

/*
    Obtener el que tiene un MEJOR fitness de la población. También la posición que ocupa
*/
pair<Cromosoma, int> mejor(const vector<Cromosoma> &poblacion){
    Cromosoma mejor;
    int pos = -1;
    mejor.fitness =  INT_MAX;

    for(int i=0; i<poblacion.size(); ++i){
        if(poblacion[i].fitness < mejor .fitness){
            mejor = poblacion[i];
            pos = i;
        }
    }

    return pair<Cromosoma, int>(mejor, pos);
}

/*
    Obtener el que tiene un PEOR fitness de la población. También la posición que ocupa
*/
pair<Cromosoma, int> peor(const vector<Cromosoma> &poblacion){
    Cromosoma peor;
    int pos;
    peor.fitness =  -1;

    for(int i=0; i<poblacion.size(); ++i){
        if(poblacion[i].fitness > peor .fitness){
            peor = poblacion[i];
            pos = i;
        }
    }

    return pair<Cromosoma, int>(peor, pos);
}

/*
    SELECCIÓN POR TORNEO: seleccionamos un total de k individuos para que se enfrenten y seleccionamos el mejor.
    Repetimos hasta obtener el tamaño deseado.
*/
void seleccion(const vector<Cromosoma> &poblacion, int k, int tam_selec, vector<Cromosoma> &seleccionados){
    srand(time(NULL));
    seleccionados.resize(tam_selec);

    vector<Cromosoma> pob_aux(poblacion);
    int introducidos = 0;

    while(introducidos < tam_selec){
        vector<int> indices;
        indices.resize(pob_aux.size());
        for(int i=0; i<pob_aux.size(); ++i){
            indices[i] = i;
        }
        random_shuffle(indices.begin(), indices.end()); //Los mezclamos 
        indices.resize(k);


        vector<int> aux(k);  //Guarda la posición
        vector<Cromosoma> aux2(k); //Guarda el cromosoma
        for(int i=0;i<indices.size();++i){
            aux[i] = indices[i];
            aux2[i] = pob_aux[indices[i]];
        }

        pair<Cromosoma, int> par= mejor(aux2); //Obtenemos el mejor
        seleccionados[introducidos] = par.first;
        pob_aux.erase(pob_aux.begin()+aux[par.second]); //Borramos recuperando la posición

        ++introducidos;
    }

}

/*
    SELECCIÓN POR TORNEO CON REEMPLAZAMIENTO: seleccionamos un total de k individuos para que se enfrenten y 
    seleccionamos el mejor, pudiendo volver a tomarse este. Repetimos hasta obtener el tamaño deseado.
*/

void seleccionReemplazamiento(const vector<Cromosoma> &poblacion, int k, int tam_selec, vector<Cromosoma> &seleccionados){
    srand(time(NULL));
    seleccionados.resize(tam_selec);

    int introducidos = 0;
    while(introducidos < tam_selec){
        vector<Cromosoma> aux(poblacion);
        random_shuffle(aux.begin(), aux.end()); //Los mezclamos de manera aleatoria
        aux.resize(k);

        //cout << "Mostramos aux" << endl;
        //mostrarFitness2(aux);

        seleccionados[introducidos] = mejor(aux).first; 

        ++introducidos;
    }
}

/*
    SELECCIÓN POR TORNEO (variante): seleccionamos un total de k individuos para que se enfrenten y seleccionamos el mejor.
    Repetimos hasta obtener el tamaño deseado. Incluimos directamente el mejor y el peor para obtener diversidad
*/
void seleccionExtremos(const vector<Cromosoma> &poblacion, int k, int tam_selec, vector<Cromosoma> &seleccionados){
    srand(time(NULL));
    seleccionados.resize(tam_selec);

    int introducidos = 2;
    
    vector<Cromosoma> pob_aux(poblacion);
    pair<Cromosoma, int> mej= mejor(pob_aux);
    seleccionados[0] = mej.first;
    pob_aux.erase(pob_aux.begin()+mej.second);
    pair<Cromosoma, int> per = peor(pob_aux);
    seleccionados[1] = per.first;
    pob_aux.erase(pob_aux.begin()+per.second);

    introducidos = 2;
    while(introducidos < tam_selec){
        vector<int> indices;
        indices.resize(pob_aux.size());
        for(int i=0; i<pob_aux.size(); ++i){
            indices[i] = i;
        }
        random_shuffle(indices.begin(), indices.end()); //Los mezclamos de manera aleatoria
        indices.resize(k);

        vector<pair<Cromosoma, int> > aux(k);
        vector<Cromosoma> aux2(k);
        for(int i=0;i<indices.size();++i){
            aux[i] = pair<Cromosoma, int>(pob_aux[indices[i]], indices[i]);
            aux2[i] = pob_aux[indices[i]];
        }


        pair<Cromosoma, int> par= mejor(aux2); 
        seleccionados[introducidos] = par.first;
        pob_aux.erase(pob_aux.begin()+aux[par.second].second); 

        ++introducidos;
    }
}

/*
    SELECCIÓN POR TORNEO CON REEMPLAZAMIENTO (variante): seleccionamos un total de k individuos para que se enfrenten y 
    seleccionamos el mejor, pudiendo volver a tomarse este. Repetimos hasta obtener el tamaño deseado.
    Incluimos directamente el mejor y el peor para obtener diversidad.
*/
void seleccionExtremosReemplazamiento(const vector<Cromosoma> &poblacion, int k, int tam_selec, vector<Cromosoma> &seleccionados){
    srand(time(NULL));
    seleccionados.resize(tam_selec);
    seleccionados[0] = mejor(poblacion).first;
    seleccionados[1] = peor(poblacion).first;

    int introducidos = 2;
    while(introducidos < tam_selec){
        vector<Cromosoma> aux = poblacion;
        random_shuffle(aux.begin(), aux.end()); //Los mezclamos de manera aleatoria
        aux.resize(k);


        seleccionados[introducidos] = mejor(aux).first; 

        ++introducidos;
    }
}