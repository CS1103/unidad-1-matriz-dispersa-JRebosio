//
// Created by Usuario on 4/09/2019.
//

#include "MatrizDispersa.h"
#include <iostream>
#include <vector>

using namespace std;


template<typename T>
MatrizDispersa<T>::MatrizDispersa(int n) {

    this->constructor(n,n);

}



template<typename T>
MatrizDispersa<T>::MatrizDispersa(int nf, int nc) {

    this->constructor(nf,nc);
}

template<typename T>
MatrizDispersa<T>::~MatrizDispersa(void) {

}


template<typename T>
MatrizDispersa<T> &MatrizDispersa<T>::set(T val, int fila, int columna) {
    for (int p= (*(this->filas))[fila];p < (*(this->filas))[fila+1] ; p++) {
        if (columna <= (*(this->columnas))[p])
            break;

        if((*(this->columnas))[p]!=columna){
            this->valores->insert(this->columnas->begin() + p, val);
            this->columnas->insert(this->columnas->begin() + p, columna);
            for (int i = fila+1 ; i <= this->f; i++) {
                (*(this->filas))[i] += 1;
            }
        }
        else {
            (*(this->valores))[p] = val;
        }
    }
    return *this;
}


template<typename T>
T MatrizDispersa<T>::get(int fila, int columna) const {
    for (int p = (*(this->filas))[fila]; p < (*(this->filas))[fila+1]; ++p) {
        if ((*(this->columnas))[p]==columna) {
            return (*(this->valores))[p];
        }
    }
    return T();
}


template<typename T>
MatrizDispersa<T> MatrizDispersa<T>::operator*(const MatrizDispersa<T> &m) const {
    MatrizDispersa<T> producto(this->fila, m.columna);
    T elemento;
    for (int i = 0; i < this->m; i++) {
        for (int j = 0; j <  m.n; j++) {
            elemento = T();
            for (int k = 0; k < this->n; k++) {
                elemento += this->get(i, k) * m.get(k, j);
            }
            producto.set(elemento, i, j);
        }
    }

    return producto;
}

template<typename T>
vector<T> MatrizDispersa<T>::operator*(const vector<T> &x) const {

    vector<T> producto(this->f, 0);

        for (int i = 0; i < this->f; i++)
            for (int j = (*(this->filas))[i]; j < (*(this->filas))[i + 1]; j++)
                producto[i]  += (*(this->valores))[j] * x[(*(this->columnas))[j]];


    return producto;

}



template<typename T>
MatrizDispersa<T> MatrizDispersa<T>::operator+(const MatrizDispersa<T> &m) const {

    MatrizDispersa<T> suma(this->m, this->n);

    for (int i = 0; i < this->m; i++)
        for (int j = 0; j < this->n; j++)
            suma.set(this->get(i, j) + m.get(i, j), i, j);

    return suma;
}

template<typename T>
void MatrizDispersa<T>::constructor(int fil, int col) {

    this->f = fil;
    this->c = col;

    this->valores = NULL;
    this->columnas = NULL;
    this->filas = new vector<int>(fil + 1, 0);

}


