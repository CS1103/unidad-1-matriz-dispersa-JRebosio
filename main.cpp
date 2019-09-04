#include <vector>
#include <iostream>

using namespace std;




int main()
{
    srand(time(NULL));

    try {

        PruebaContructor();
        PruebaSuma();
        PruebaResta();
        PruebaProducto();
    } catch (const FailureException & e) {
        cout << "FALLA" << e.what() << "'" << endl;
        return 1;
    }


    MatrixDispersa < int > matrix ( 3 );
    MatrizDispersa < int > matrix2 ( 4 , 5 );

    int val;
    matrix.set (- 5 , 2 , 3 );
    val = matrix.get ( 2 , 3 );
    cout<<val;


    MatrizDispersa<int> mtr(9, 10);
    vector<int> vct7, 3);

    vector<int> result;
    resultado = mtr.producto(vct);
    resultado = mtr * vct;


    return 0;
}
