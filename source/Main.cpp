/*********************************************************
   Fichero: Matrices.hpp
   Autor: Imar Abreu Diaz, Carlos García González, Richard Morales Luis
   Fecha de creación: 16/03/2017
   Contenido: Declaración de la clase matriz_t
 **********************************************************/

#include "Cadenas_de_matrices.hpp"
#include "Matrices.hpp"
#include <chrono>


typedef chrono::high_resolution_clock Clock;
int main (int argc, char* argv[]){

	cadena_t chain(10);
	cout << chain;

	matriz_t aux;

	auto t1 = Clock :: now();
 	aux = chain.multiplicacion_clasica();
 	auto t2 = Clock :: now();
 	//cout << aux;

 	auto t3 = Clock :: now();
 	aux = chain.multiplicacion_prog_dinamica();
 	auto t4 = Clock :: now();
  	//cout << aux;

	cout << "Tiempo por el algoritmo de fuerza bruta: " << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " microsegundos" << endl;
	cout << "Tiempo invertido por el algoritmo de programación dinámica: " << chrono::duration_cast<chrono::microseconds>(t4 - t3).count() << " microsegundos" << endl;
	cin.get();

	return(0);

}
