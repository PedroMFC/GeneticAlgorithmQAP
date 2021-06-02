#ifndef __INCLUDES
#define __INCLUDES

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>      // std::pair, std::make_pair
#include <time.h>       /* time */
using namespace std;

extern int **m_distancias;
extern int **m_flujo;
extern int size;

struct Cromosoma{
    vector<int> permutacion;
    int fitness;
};

void loadMatrixes(string file);
int fitness(const vector<int> &permutacion, int coste_ant = -1, int i_ant = 0, int j_ant = 0);
void evaluar(vector<Cromosoma> &poblacion);
void poblacion_inicial(vector<Cromosoma> &poblacion);

//Selección
pair<Cromosoma, int>  mejor(const vector<Cromosoma> &poblacion);
pair<Cromosoma, int> peor(const vector<Cromosoma> &poblacion);
void seleccion(const vector<Cromosoma> &poblacion, int k, int tam_selec, vector<Cromosoma> &seleccionados);
void seleccionReemplazamiento(const vector<Cromosoma> &poblacion, int k, int tam_selec, vector<Cromosoma> &seleccionados);
void seleccionExtremos(const vector<Cromosoma> &poblacion, int k, int tam_selec, vector<Cromosoma> &seleccionados);
void seleccionExtremosReemplazamiento(const vector<Cromosoma> &poblacion, int k, int tam_selec, vector<Cromosoma> &seleccionados);

//Cruce
void cruzar(vector<Cromosoma> seleccionados, int tamanio_pob_hijos, vector<Cromosoma> &hijos);

//Mutación
Cromosoma mutacionNoModifica(const Cromosoma crom, int i, int j);
void mutar_hijos(vector<Cromosoma> &hijos);

//Reemplazo
vector<Cromosoma> reemplazoElitismo(vector<Cromosoma> &padres, vector<Cromosoma> &hijos, int tamanio_pob);
vector<Cromosoma> reemplazoElitismoPeor(vector<Cromosoma> &padres, vector<Cromosoma> &hijos, int tamanio_pob);
vector<Cromosoma> reemplazoFitness(vector<Cromosoma> &padres, vector<Cromosoma> &hijos, int tamanio_pob);
vector<Cromosoma> reemplazoFitnessPeor(vector<Cromosoma> &padres, vector<Cromosoma> &hijos, int tamanio_pob);

#endif