#include "../include/includes.h"
#include <algorithm>    // std::sort
#include <iostream>
using namespace std;

/*
 Sustituimos la población entera por la nueva generación de hijos, salvo que incluimos el mejor,
 ya sea padre o hijo 
*/
vector<Cromosoma> reemplazoElitismo(vector<Cromosoma> &padres, vector<Cromosoma> &hijos, int tamanio_pob){
    vector<Cromosoma> nueva_poblacion(hijos);

    Cromosoma mejor_padre = mejor(padres).first;
    Cromosoma mejor_hijo = mejor(hijos).first;

    if(mejor_padre.fitness < mejor_hijo.fitness){
        nueva_poblacion[0] = mejor_padre;
    }

    nueva_poblacion.resize(tamanio_pob);
    return nueva_poblacion;
}

/*
 Sustituimos la población entera por la nueva generación de hijos, salvo que incluimos el mejor,
 ya sea padre o hijo. También incluimos el peor padre para mantener la diversidad de la población
*/
vector<Cromosoma> reemplazoElitismoPeor(vector<Cromosoma> &padres, vector<Cromosoma> &hijos, int tamanio_pob){
    vector<Cromosoma> nueva_poblacion(hijos);

    Cromosoma mejor_padre = mejor(padres).first;
    Cromosoma peor_padre = peor(padres).first;
    Cromosoma mejor_hijo = mejor(hijos).first;

    nueva_poblacion[0] = peor_padre;
    if(mejor_padre.fitness < mejor_hijo.fitness){
        nueva_poblacion[1] = mejor_padre;
    }

    nueva_poblacion.resize(tamanio_pob);
    return nueva_poblacion;
}



bool miOrden (Cromosoma i,Cromosoma j) { return (i.fitness<j.fitness); }

/*
    Nos quedamos solamente con aquellos individuos que presenten un mejor valor de fitness
*/
vector<Cromosoma> reemplazoFitness(vector<Cromosoma> &padres, vector<Cromosoma> &hijos, int tamanio_pob){
    vector<Cromosoma> nueva_poblacion(padres);

    for(int i = 0; i<hijos.size(); ++i){
        nueva_poblacion.push_back(hijos[i]);
    }


    sort(nueva_poblacion.begin(), nueva_poblacion.end(), miOrden);

    nueva_poblacion.resize(tamanio_pob);
    return nueva_poblacion;
}

/*
    Nos quedamos solamente con aquellos individuos que presenten un mejor valor de fitness,
    salvo que también incluimos el peor hijo y padre para mantener la diversidad
*/
vector<Cromosoma> reemplazoFitnessPeor(vector<Cromosoma> &padres, vector<Cromosoma> &hijos, int tamanio_pob){
    vector<Cromosoma> nueva_poblacion(padres);

    Cromosoma peor_padre = peor(padres).first;
    Cromosoma peor_hijo = peor(hijos).first;
    

    for(int i = 0; i<hijos.size(); ++i){
        nueva_poblacion.push_back(hijos[i]);
    }


    sort(nueva_poblacion.begin(), nueva_poblacion.end(), miOrden);

    nueva_poblacion.resize(tamanio_pob-2);
    nueva_poblacion.push_back(peor_padre);
    nueva_poblacion.push_back(peor_hijo);
    return nueva_poblacion;
}