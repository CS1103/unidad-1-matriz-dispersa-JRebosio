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
    for (int p= (*(this->filas))[fila];p < (*(this->filas))[fila+1] - 1; p++) {
        if (columna <= (*(this->columnas))[p])
            break;

        if((*(this->cols))[p]!=columna){
            this->valores->insert(this->columnas->begin() + p, val);
            this->columnas->insert(this->columnas->begin() + p, columna);
            for (int i = fila; i <= this->f; i++) {
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
    return MatrizDispersa<T>(0);
}

template<typename T>
vector<T> MatrizDispersa<T>::operator*(const vector<T> &x) const {

    vector<T> producto(this->c, 0);

        for (int i = 0; i < this->columnas; i++)
            for (int j = (*(this->rows))[i]; j < (*(this->rows))[i + 1]; j++)
                producto[i]  += (*(this->valores))[j] * x[(*(this->cols))[j]];


    return producto;

}



template<typename T>
MatrizDispersa<T> MatrizDispersa<T>::operator+(const MatrizDispersa<T> &m) const {

    MatrizDispersa<T> suma(this->m, this->n);

    for (int i = 1; i <= this->m; i++)
        for (int j = 1; j <= this->n; j++)
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
