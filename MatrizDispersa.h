//
// Created by Usuario on 4/09/2019.
//

#ifndef PROYECTO_2_MATRIZDISPERSA_H
#define PROYECTO_2_MATRIZDISPERSA_H

#include <vector>
#include <iostream>


using namespace std;

template<typename T>
class MatrizDispersa {
public:

    MatrizDispersa(int n);
    MatrizDispersa(int filas, int columnas);
    ~MatrizDispersa(void);

    MatrizDispersa & set(T val, int fila, int columna);
    T get(int fila, int columna) const;

    vector<T> operator * (const vector<T> & x) const;

    MatrizDispersa<T> operator * (const MatrizDispersa<T> & m) const;


    MatrizDispersa<T> operator + (const MatrizDispersa<T> & m) const;



protected:
    int f, c;
    vector<T> * valores;
    vector<int>  * filas, * columnas;
    void constructor(int f, int c);
    void destruct(void);



};


#endif //PROYECTO_2_MATRIZDISPERSA_H
