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
MatrizDispersa<T>::MatrizDispersa(int filas, int columnas) {
    this->constructor(filas,columnas);
}

template<typename T>
MatrizDispersa<T>::~MatrizDispersa(void) {
    this->destruct();
}


template<typename T>
MatrizDispersa<T> &MatrizDispersa<T>::set(T val, int fila, int columna) {
    int p=0;
    int ccol=0;
    for (p= (*(this->filas))[fila];p < (*(this->filas))[fila+1] ; p++) {
        ccol=(*(this->columnas))[p];
        if (columna <= ccol)
            break;
    }
        if(ccol!=columna || (ccol==0 && columna==0 )) {
            if (this->valores == NULL) {
                this->valores = new vector<T>(1, val);
                this->columnas = new vector<int>(1, columna);
            } else {
                this->valores->insert(this->valores->begin() + p, val);
                this->columnas->insert(this->columnas->begin() + p, columna);
                }
            for (int i = fila + 1; i <= this->f; i++) {
                (*(this->filas))[i] += 1;
            }
        }
        else {

            (*(this->valores))[p] = val;
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
void MatrizDispersa<T>::constructor(int filas, int columnas) {

    this->f = filas;
    this->c = columnas;

    this->valores = NULL;
    this->columnas = NULL;
    this->filas = new vector<int>(filas + 1, 0);

}


template<typename T>
void MatrizDispersa<T>::destruct(void) {
    if (this->valores != NULL) {
        delete this->valores;
        delete this->columnas;
    }

    delete this->filas;

}


