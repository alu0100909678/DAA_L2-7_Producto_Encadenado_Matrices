/*********************************************************
   Fichero: Matrices.hpp
   Autor: Imar Abreu Diaz, Carlos García González, Richard Morales Luis
   Fecha de creación: 16/03/2017
   Contenido: Declaración de la clase matriz_t
 **********************************************************/

#include "Matrices.hpp"
#include <algorithm>
  
#pragma once
  
using namespace std;

class cadena_t {

private:

vector<matriz_t> chain_;
vector<int> dimensiones_;
matriz_t solucion_;
matriz_t solucion_indice_;

public:
/**
 * Construcor por defecto.
 */
cadena_t();                 	
/**
 * Constructor parametrizado.
 * @param cantidad
 */
cadena_t(int cantidad);	
/**
 * Constructor de copia.
 * @param matriz
 */
cadena_t(const cadena_t& matriz);          				
/**
 * Destructor por defecto.
 */
~cadena_t();                    
/**
 * LLama al algoritmo de fuerza bruta.
 * @return 
 */
matriz_t multiplicacion_clasica (void);
/**
 * Realiza el algoritmo de fuerza bruta.
 * @return 
 */
matriz_t multiplicacion_fuerza_bruta (void); 
/**
 * Comprueba multiplicacion valida.
 * @param orden
 * @return 
 */
bool comprueba_permutacion (vector<int> orden);
/**
 * Multiplica las matrices.
 * @param matriz1
 * @param matriz2
 * @return 
 */
matriz_t multiplicar_matrices_clasico (const matriz_t& matriz1, const matriz_t& matriz2);
/**
 * Realiza el algoritmo de programacion dinamica.
 * @return 
 */
matriz_t multiplicacion_prog_dinamica (void);
/**
 * Rellena la matriz que contiene la cantidad optima de multiplicaciones.
 * @return 
 */
matriz_t rellena_matriz_solucion (void);
/**
 * Devuelve el numero minimo de multiplicaciones.
 * @param i
 * @param j
 * @return 
 */
int minimo_producto (int i, int j);	
/**
 * Realiza la multipplicacion con solucion indice.
 * @param i
 * @param j
 * @return 
 */
matriz_t multiplica_cadena_matrices (int i, int j);
/**
 * Sobrecarga del operador << para mostrar por pantalla.
 */
friend ostream& operator<< (ostream& salida, cadena_t& aux);
};
