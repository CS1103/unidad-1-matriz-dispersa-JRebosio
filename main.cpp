#include <vector>
#include <iostream>
#include "MatrizDispersa.cpp"
#include "MatrizDispersa.h"
#include <ctime>

using namespace std;




int main()
{
    //srand(time(NULL));
    /*
    try {

        PruebaContructor();
        PruebaSuma();
        PruebaResta();
        PruebaProducto();
    } catch (const FailureException & e) {
        cout << "FALLA" << e.what() << "'" << endl;
        return 1;
    }
     */




    MatrizDispersa < int > matrix ( 3 );
    MatrizDispersa < int > matrix2 ( 4 , 5 );

    int val;
    matrix.set(4,0,1);
    matrix.set(5,1,1);

    matrix.set(1,2,2);
    val = matrix.get(1,1);
    cout<<val<<"hola";
    vector<int> resultado;
   // vector<int> ggg{0, 2, 3};
   //resultado =  matrix*ggg;

   // cout<<matrix.get(2,2);

    /*for(int u:resultado){
        printf("%d", u);
    }*/


    return 0;
}
