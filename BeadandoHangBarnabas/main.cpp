#include <iostream>
#include "MatrixBarnabas.h"
using namespace std;

int main()
{
    MatrixBarnabas proba;
    proba.printMatrixFull();
    ++proba;
    ++proba;
    ++proba;
    ++proba;
    ++proba;
    ++proba;
    cout<<endl;

    proba.printMatrixFull();
    cout<<endl;

    --proba;
    --proba;
    --proba;
    --proba;
    --proba;
    --proba;

    proba.printMatrixFull();



    return 0;
}
