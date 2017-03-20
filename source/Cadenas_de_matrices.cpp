/*********************************************************
   Fichero: Matrices.hpp
   Autor: Imar Abreu Diaz, Carlos García González, Richard Morales Luis
   Fecha de creación: 16/03/2017
   Contenido: Declaración de la clase matriz_t
 **********************************************************/

#include "Cadenas_de_matrices.hpp"


cadena_t :: cadena_t(){}

cadena_t :: cadena_t(int cantidad):

	solucion_(cantidad, cantidad),
	solucion_indice_(cantidad, cantidad)

{

	srand(time(NULL));
	int columnas_filas1 = (rand() % 10) + 1;
	int columnas_filas2 = (rand() % 10) + 1;

	for(int i = 0; i < cantidad; i++){

		if((i % 2) == 0){

			matriz_t aux(columnas_filas1, columnas_filas2);
			aux.rellena_random();
			this->chain_.push_back(aux);
			columnas_filas1 = (rand() % 10) + 1;

		}

		else{

			matriz_t aux(columnas_filas2, columnas_filas1);
			aux.rellena_random();
			this->chain_.push_back(aux);
			columnas_filas2 = (rand() % 10) + 1;

		}

	}

	this->dimensiones_.push_back(this->chain_[0].get_filas());
	this->dimensiones_.push_back(this->chain_[0].get_columnas());

	int j = this->dimensiones_.size() - 1;

	for(int i = 1; i < this->chain_.size(); i++){

		this->dimensiones_.push_back(this->chain_[i].get_columnas());

	}

}



cadena_t :: cadena_t(const cadena_t& matriz){}



cadena_t :: ~cadena_t(){}



matriz_t cadena_t :: multiplicacion_clasica (void){

	matriz_t resultado;
	resultado = this->multiplicacion_fuerza_bruta();

	return(resultado);

}



matriz_t cadena_t :: multiplicacion_fuerza_bruta (void){

	vector<int> orden;
	vector<vector<int> > ordenes_validos;

	for(int i = 0; i < this->chain_.size(); i++){

		orden.push_back(i);

	}

	do{

		if(this->comprueba_permutacion(orden)){

			ordenes_validos.push_back(orden);

		}

  	}while(next_permutation(orden.begin(), orden.end()));

  	int min = 21474836;
  	int k = -1;
  	int acumulado = 0;

  	for(int i = 0; i < ordenes_validos.size(); i++){

  		for(int j = 1; j < ordenes_validos[i].size(); j++){

  			acumulado += this->chain_[ordenes_validos[i][j-1]].get_filas() * this->chain_[ordenes_validos[i][j]].get_filas() * this->chain_[ordenes_validos[i][j]].get_columnas();

  		}

  		if(min > acumulado){

  			min = acumulado;
  			k = i;

  		}

  		acumulado = 0;

  	}

  	matriz_t resultado;
	resultado = this->multiplicar_matrices_clasico(this->chain_[ordenes_validos[k][0]], this->chain_[ordenes_validos[k][1]]);

	for(int i = 2; i < this->chain_.size(); i++){

		resultado = this->multiplicar_matrices_clasico(resultado, this->chain_[ordenes_validos[k][i]]);

	}

	return(resultado);

}



bool cadena_t :: comprueba_permutacion (vector<int> orden){

	for(int i = 1; i < orden.size(); i++){

		if(this->chain_[orden[i-1]].get_columnas() != this->chain_[orden[i]].get_filas()){

			return(false);

		}

	}

	return(true);

}



matriz_t cadena_t :: multiplicar_matrices_clasico (const matriz_t& matriz1, const matriz_t& matriz2){

	matriz_t resultado(matriz1.get_filas(), matriz2.get_columnas());
	long int aux = 0;

	for(int i = 0; i < matriz1.get_filas(); i++){

		for(int j = 0; j < matriz2.get_columnas(); j++){

			aux = 0;

			for(int k = 0; k < matriz1.get_columnas(); k++){

				aux += matriz1.get_elemento(i, k) * matriz2.get_elemento(k, j);

			}

			resultado.set_elemento(i, j, aux);

		}

	}

	return(resultado);

}



matriz_t cadena_t :: multiplicacion_prog_dinamica (void){

	matriz_t resultado;
	resultado = this->rellena_matriz_solucion();

	return(resultado);

}



matriz_t cadena_t :: rellena_matriz_solucion (void){

	for(int i = 0; i < this->solucion_.get_filas(); i++){

		this->solucion_.set_elemento(i, i, 0);

	}

	matriz_t resultado;

	for(int diagonal = 1; diagonal < this->solucion_.get_filas(); diagonal++){

		for(int i = 0; i < this->solucion_.get_filas() - diagonal; i++){

			this->solucion_.set_elemento(i, i + diagonal, this->minimo_producto(i, i + diagonal));
			resultado = this->multiplica_cadena_matrices(i, i + diagonal);

		}



	}

	return(resultado);

}



int cadena_t :: minimo_producto (int i, int j){

	int aux = 0;
	int min = 21474836;

	for (int k = i; k < j; k++){

		aux = this->solucion_.get_elemento(i, k) + this->solucion_.get_elemento(k+1, j) + (this->dimensiones_[i] * this->dimensiones_[k+1] * this->dimensiones_[j+1]);

		if(aux < min){

			min = aux;
			this->solucion_indice_.set_elemento(i, j, k);

		}

	}

	return(aux);

}




matriz_t cadena_t :: multiplica_cadena_matrices (int i, int j){

	if(j > i){

		matriz_t x;
		matriz_t y;

		x = this->multiplica_cadena_matrices(i, this->solucion_indice_.get_elemento(i, j));
		y = this->multiplica_cadena_matrices(this->solucion_indice_.get_elemento(i, j)+1, j);

		return(multiplicar_matrices_clasico(x, y));

	}

	else{

		return(this->chain_[i]);

	}

}



ostream& operator<< (ostream& salida, cadena_t& aux){

	for(int i = 0; i < aux.chain_.size(); i++){

		salida << "Matriz " << i << ":" << " M" << aux.chain_[i].get_filas() << "x" << aux.chain_[i].get_columnas() << endl;
		salida << aux.chain_[i] << endl << endl;

	}

	return(salida);

}
