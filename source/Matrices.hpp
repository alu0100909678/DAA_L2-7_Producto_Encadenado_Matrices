/*********************************************************
   Fichero: Matrices.hpp
   Autor: Imar Abreu Diaz, Carlos García González, Richard Morales Luis
   Fecha de creación: 16/03/2017
   Contenido: Declaración de la clase matriz_t
 **********************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#pragma once

using namespace std;

class matriz_t {

private:

vector<vector<long int> > matrix_;
int filas_;
int columnas_;

public:
/**
 * Constructor por defecto.
 */
matriz_t();
/**
 * Constructor parametrizado.
 * @param n
 * @param m
 */
matriz_t(int n, int m);
/**
 * Constructor parametrizado.
 * @param matriz
 */
matriz_t(const matriz_t& matriz);
/**
 * Destructor por defecto.
 */
~matriz_t();
/**
 * Rellena la matriz de forma aleatoria.
 */
void rellena_random (void);
/**
 * Devuelve el numero de la matriz i,j.
 * @param i
 * @param j
 * @return 
 */
int get_elemento (int i, int j) const;
/**
 * Guarda el elemento dato en la posicion de la matriz i,j.
 * @param i
 * @param j
 * @param dato
 */
void set_elemento (int i, int j, long int dato);
/**
 * Devuelve el numero de filas de la matriz.
 * @return 
 */
int get_filas (void) const;
/**
 * Devuelve el numero de columnas de la matriz.
 * @return 
 */
int get_columnas (void) const;
/**
 * Sobre carga del operador = para matrices.
 * @param aux
 * @return 
 */
matriz_t& operator= (const matriz_t& aux);
/**
 * Sobrecarga del operador << para mostrar por pantalla la matriz.
 * @param salida
 * @param aux
 * @return
 */
friend ostream& operator<< (ostream& salida, matriz_t& aux);
};
