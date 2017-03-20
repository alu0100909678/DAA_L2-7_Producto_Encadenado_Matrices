/*********************************************************
   Fichero: Matrices.hpp
   Autor: Imar Abreu Diaz, Carlos García González, Richard Morales Luis
   Fecha de creación: 16/03/2017
   Contenido: Declaración de la clase matriz_t
 **********************************************************/

#include "Matrices.hpp"


matriz_t :: matriz_t():

	filas_(0),
	columnas_(0)

{}



matriz_t :: matriz_t(int n, int m){

	this->filas_ = n;
	this->columnas_ = m;

	this->matrix_.resize(n);

	for(int i = 0; i < this->matrix_.size(); i++){

		for(int j = 0; j < m; j++){

			this->matrix_[i].push_back(0);

		}

	}

}



matriz_t :: matriz_t(const matriz_t& matriz){

	this->filas_ = matriz.filas_;
	this->columnas_ = matriz.columnas_;

	this->matrix_.resize(matriz.filas_);

	for(int i = 0; i < matriz.filas_; i++){

		for(int j = 0; j < matriz.columnas_; j++){

			this->matrix_[i].push_back(matriz.matrix_[i][j]);

		}

	}

}



matriz_t :: ~matriz_t(){}



void matriz_t :: rellena_random (void){

	//srand(time(NULL));

	for(int i = 0; i < this->matrix_.size(); i++){

		for(int j = 0; j < this->matrix_[i].size(); j++){

			this->matrix_[i][j] = rand() % 10;

		}

	}

}



int matriz_t :: get_elemento (int i, int j) const{

	return(this->matrix_[i][j]);

}



void matriz_t :: set_elemento (int i, int j, long int dato){

	this->matrix_[i][j] = dato;

}



int matriz_t :: get_filas (void) const{

	return(this->filas_);

}


int matriz_t :: get_columnas (void) const{

	return(this->columnas_);

}



matriz_t& matriz_t :: operator= (const matriz_t& aux){

	this->filas_ = aux.filas_;
	this->columnas_ = aux.columnas_;

	this->matrix_.clear();
	this->matrix_.resize(aux.filas_);

	for(int i = 0; i < aux.filas_; i++){

		for(int j = 0; j < aux.columnas_; j++){

			this->matrix_[i].push_back(aux.matrix_[i][j]);

		}

	}

	return(*this);

}



ostream& operator<< (ostream& salida, matriz_t& aux){

	for(int i = 0; i < aux.matrix_.size(); i++){

		for(int j = 0; j < aux.matrix_[i].size(); j++){

			salida << aux.matrix_[i][j] << " ";

		}

		salida << endl;

	}

	return(salida);

}
